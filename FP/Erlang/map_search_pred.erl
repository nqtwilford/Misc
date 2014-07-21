-module(map_search_pred).
-export([map_search_pred/2, test/0]).

map_search_pred(Map, Pred) ->
	list_search_pred(maps:to_list(Map), Pred).

list_search_pred(List, Pred) ->
	[H|T] = List,
	{Key, Value} = H,
	case Pred(Key, Value) of
		true -> {Key, Value};
		false -> list_search_pred(T, Pred)
	end.

test() ->
	Pred = fun(Key, Value) -> Key =:= Value end,
	Map = #{name => zhangwei, age => 27},
	try map_search_pred(Map, Pred)
	catch
		error:{badmatch, _} -> "no match result";
		error:X -> {error, X};
		throw:X -> {throw, X};
		exit:X -> {exit, X}
	end.
