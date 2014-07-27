-module(link).
-import(monitor, [on_exit/2]).
-export([test/0]).

link_all(FunList) when is_list(FunList) ->
	spawn(fun() ->
				  PidList = [spawn_link(F) || F <- FunList],
				  receive
					  crash ->
						  [FirstPid | _T] = PidList,
						  FirstPid ! crash,
						  receive
						  after infinity -> true
						  end
				  after infinity -> true
				  end
		  end).

test() ->
	F = fun() -> 
				receive
					crash ->
						exit("crashed for msg.")
				after infinity -> true
				end
		end,
	PidMain = link_all([F, F, F]),
	on_exit(PidMain, fun({_Pid, Why}) ->
						 io:format("Main proc crash, ~p~n", [Why])
				 end),
	PidMain ! crash.
