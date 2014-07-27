-module(args).
-export([main/1]).

main([A]) ->
	io:format("~p~n", [A]),
	init:stop().
