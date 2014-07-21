-module(math_funcs).
-export([odd/1, even/1, filter/2, split/1, split1/1]).

odd(X) ->
	X rem 2 =/= 0.

even(X) ->
	X rem 2 =:= 0.

filter(F, L) ->
	[X || X <- L, F(X)].

split(L) -> split(L, [], []).
split([H|T], Odds, Evens) ->
	case even(H) of
		true -> split(T, Odds, [H|Evens]);
		false -> split(T, [H|Odds], Evens)
	end;
split([], Odds, Evens) -> 
	{lists:reverse(Odds), lists:reverse(Evens)}.

split1(L) ->
	{filter(fun odd/1, L), filter(fun even/1, L)}.
