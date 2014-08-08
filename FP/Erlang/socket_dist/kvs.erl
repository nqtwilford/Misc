-module(kvs).
-export([start/0, store/2, lookup/1]).

start() -> register(kvs, spawn(fun() -> loop() end)).

loop() ->
	receive
		{From, {store, Key, Value}} ->
			io:format("save key:~p for value:~p.~n", [Key, Value]),
			put(Key, {ok, Value}),
			From ! {kvs, true},
			loop();
		{From, {lookup, Key}} ->
			io:format("get key:~p.~n", [Key]),
			From ! {kvs, get(Key)},
			loop()
	end.

rpc(Q) ->
	kvs ! {self(), Q},
	receive
		{kvs, Reply} ->
			Reply
	end.

store(Key, Value) -> rpc({store, Key, Value}).

lookup(Key) -> rpc({lookup, Key}).
