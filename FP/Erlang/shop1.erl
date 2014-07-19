-module(shop1).
-export([total/1, get_buy_list/0]).
-import(lists, [map/2, sum/1]).

get_buy_list() -> [{orange, 4}, {newspaper, 1}, {apple, 5}, {pear, 6}, {milk, 3}].

cost(orange) -> 5;
cost(newspaper) -> 8;
cost(apple) -> 2;
cost(pear) -> 9;
cost(milk) -> 7.

total(L) ->
	sum(map(fun({What, N}) -> cost(What) * N end, L)).
