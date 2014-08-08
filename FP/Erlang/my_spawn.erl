-module(my_spawn).
-export([proc/0, proc1/0, test/0, test1/0, test2/0, test3/0]).
-import(monitor, [on_exit/2]).

-spec my_spawn(Mod, Func, Args) -> Pid when
	  Mod :: atom() | tuple(),
	  Func :: atom(),
	  Args :: [any()],
	  Pid :: pid().

-spec my_spawn(Mod, Func, Args, Time) -> Pid when
	  Mod :: atom() | tuple(),
	  Func :: atom(),
	  Args :: [any()],
	  Time :: pos_integer(),
	  Pid :: pid().

-spec spawn_funcs_respawn([{Mod, Func, Args}]) -> [Pid] when
	  Mod :: atom() | tuple(),
	  Func :: atom(),
	  Args :: [any()],
	  Pid :: pid().

-spec spawn_funcs_respawn_all([{Mod, Func, Args}]) -> [Pid] when
	  Mod :: atom() | tuple(),
	  Func :: atom(),
	  Args :: [any()],
	  Pid :: pid().

my_spawn(Mod, Func, Args) ->
	Start = now_micro_sec(),
	Handler = fun({Pid, Why}) ->
		Down = now_micro_sec(),
		io:format("Proc ~p down. Lifetime:~ps. Reason:~p~n", [Pid, (Down - Start)/1000000, Why])
	end,
	Pid = spawn(Mod, Func, Args),
	on_exit(Pid, Handler).

my_spawn(Mod, Func, Args, Time) ->
	Deamon = fun({Pid, Why}) ->
		io:format("Proc ~p crashed for reason ~p. Restart it.~n", [Pid, Why]),
		spawn(Mod, Func, Args)
	end,
	Pid = spawn(Mod, Func, Args),
	on_exit(Pid, Deamon),
	receive
	after Time ->
		  io:format("kill proc:~p~n", [Pid]),
		  exit(Pid, "fake crash")
	end.

spawn_funcs_respawn(FuncList) ->
	[on_exit(spawn(Mod, Func, Args), get_deamon(Mod, Func, Args)) || {Mod, Func, Args} <- FuncList].

get_deamon(Mod, Func, Args) ->
	fun({Pid, Why}) ->
		io:format("Proc ~p crashed for reason ~p. Restart it.~n", [Pid, Why]),
		spawn(Mod, Func, Args)
	end.

spawn_funcs_respawn_all(FuncList) ->
	PidHead = spawn(fun() -> 
							[spawn_link(Mod, Funcs, Args) || {Mod, Funcs, Args} <- FuncList],
							receive after infinity -> 0 end
				   	end),
	on_exit(PidHead, fun({_Pid, Why}) ->
							 io:format("All procs crashed, for reason:~p, restart them.~n", [Why]),
							 spawn_funcs_respawn_all(FuncList)
					 end).

proc() ->
	io:format("proc started.~n"),
	receive crash ->
			  exit("crash for msg.")
	end.

proc1() ->
	io:format("proc1 running~n"),
	receive
	after 9000 ->
			  proc1()
	end.

test() ->
	my_spawn(my_spawn, proc, []).

test1() ->
	my_spawn(my_spawn, proc1, [], 7000).

test2() ->
	spawn_funcs_respawn([{my_spawn, proc, []}, {my_spawn, proc1, []}]).

test3() ->
	spawn_funcs_respawn_all([{my_spawn, proc, []}, {my_spawn, proc1, []}]).

now_micro_sec() ->
	{MegaSec, Sec, MicroSec} = now(),
	MegaSec * 1000000000000 + Sec * 1000000 + MicroSec.
