-module(shop).
-export([get_buy_list/0, total/1]).

get_buy_list() -> [{orange, 4}, {newspaper, 1}, {apple, 5}, {pear, 6}, {milk, 3}].

cost(orange) -> 5;
cost(newspaper) -> 8;
cost(apple) -> 2;
cost(pear) -> 9;
cost(milk) -> 7.

total([{Whar, Count}|T]) -> cost(Whar) * Count + total(T);
total([]) -> 0.

