-module(qsort).
-export([qsort/1, test/0]).

qsort([Pivot|T]) ->
	qsort([X || X <- T, X < Pivot])
	++ [Pivot] ++
	qsort([X || X <- T, X >= Pivot]);
qsort([]) -> [].

test() ->
	L = [34, 17, 9, 76, 22, 19, 34, 65, 84],
	qsort(L).
