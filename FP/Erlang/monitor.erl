-module(monitor).
-export([test/0, on_exit/2]).

on_exit(Pid, Handler) when is_pid(Pid), is_function(Handler) ->
	spawn(fun() ->
				Ref = monitor(process, Pid),
				receive
					{'DOWN', Ref, process, Pid, Why} ->
						Handler({Pid, Why})
				end
		  end).

work_proc() ->
	receive
		L ->
			list_to_atom(L)
	end.

err_handler({Pid, Why}) when is_pid(Pid) ->
	io:format("Proc: ~p down.~n", [Pid]),
	Why.

test() ->
	Handler = fun({Pid, Why}) -> err_handler({Pid, Why}) end,
	Pid = spawn(fun() -> work_proc() end),
	on_exit(Pid, Handler),
	%on_exit(Pid, err_handler),
	Pid ! atom,
	Pid.
