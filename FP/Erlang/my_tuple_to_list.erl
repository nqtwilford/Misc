-module(my_tuple_to_list).
-export([test/0, test1/0]).

my_tuple_to_list(T) ->
	my_tuple_to_list(T, 1).

my_tuple_to_list(T, Start) ->
	Size = tuple_size(T),
	if
		Start < Size ->
			[element(Start, T)|my_tuple_to_list(T, Start+1)];
		Start =:= Size ->
			[element(Start, T)]
	end.

test() ->
	T = {1, 2, 3},
	my_tuple_to_list(T).
test1() ->
	T1 = {abc, def, {g, h}},
	my_tuple_to_list(T1).
