-module(msg_ring).
-export([start/2, main/2, test/0]).

test() ->
	start(10000, 300).

start(TokenNum, MsgLoopCount) ->
	FirstToken = spawn(msg_ring, main, [1, TokenNum]),
	%io:format("FirstToken:~p~n", [FirstToken]),
	try register(firstToken, FirstToken)
	catch
	   	error:Any ->
		   	io:format("error:~p, try to unregister first.~n", [Any]),
			unregister(firstToken),
			try register(firstToken, FirstToken)
			catch
				_:Any -> io:format("error:~p~n", [Any])
			end
	end,
	%sleep(3000),
	%io:format("Msg ring estanblished, send msg.~n"),
	FirstToken ! {msg, 1, TokenNum * MsgLoopCount}.

main(TokenID, MaxTokenID) ->
	%io:format("Token: ~p spawned.~n", [TokenID]),
	if TokenID =:= 1 -> statistics(runtime);
	   true -> true
	end,
	case TokenID =/= MaxTokenID of
		true ->
			NextToken = spawn(msg_ring, main, [TokenID + 1, MaxTokenID]);
		false ->
			NextToken = whereis(firstToken)
			%io:format("FirstToken:~p~n", [NextToken])
	end,
	loop(TokenID, NextToken).

loop(TokenID, NextToken) ->
	receive
		{msg, Count, MaxCount} ->
			%io:format("Msg received at token:~p, spread count:~p~n", [TokenID, Count]),
			%sleep(1000),
			case Count =:= MaxCount of
				true ->
					%io:format("Spread complete, notify to exit.~n"),
					NextToken ! {exit};
				false ->
				   	NextToken ! {msg, Count+1, MaxCount}
			end,
			loop(TokenID, NextToken);
		{exit} when TokenID =:= 1 ->
			{_, Time1} = statistics(runtime),
			io:format("Total time: ~ps.~n", [Time1/1000]);
		{exit} ->
			%io:format("Token:~p exit.~n", [TokenID]),
			NextToken ! {exit}
	end.

sleep(T) ->
	receive after T -> true end.
