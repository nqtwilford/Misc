-module(module_analyze).
-compile(export_all).

mod_funcs(Mod) ->
	{Mod, apply(Mod, module_info, [exports])}.

mod_list() ->
	[mod_funcs(Mod) || {Mod, _File} <- code:all_loaded()].

mod_with_most_func() ->
	mod_with_most_func(mod_list(), {}).
mod_with_most_func([{Name, FuncList}|T], {}) ->
	mod_with_most_func(T, {Name, length(FuncList)});
mod_with_most_func([{Name, FuncList}|T], {NameMost, CountMost}) ->
	Count = length(FuncList),
	case Count > CountMost of
		true -> mod_with_most_func(T, {Name, Count});
	    false -> mod_with_most_func(T, {NameMost, CountMost})
	end;	 
mod_with_most_func([], {NameMost, CountMost}) ->
	{NameMost, CountMost}.

func_count() ->
	maps:to_list(func_count(mod_list(), #{})).
func_count([{_Mod, [{_FuncName, _Arity}|_RestFunc]=FuncList}|RestMod], Map) ->
	func_count(RestMod, func_count(FuncList, Map));
func_count([{FuncName, _Arity}|T], Map) ->
	case maps:is_key(FuncName, Map) of
		true -> 
			func_count(T, maps:put(FuncName, maps:get(FuncName, Map) + 1, Map));
		false ->
			func_count(T, maps:put(FuncName, 1, Map))
	end;
func_count([], Map) -> Map.

most_freq_func() ->
	most_freq_func(func_count()).
most_freq_func([{FuncName, Count}|T]) ->
	most_freq_func(T, {FuncName, Count}).
most_freq_func([{FuncName, Count}|T], {MostName, MostCount}) ->
	case Count > MostCount of
		true -> most_freq_func(T, {FuncName, Count});
		false -> most_freq_func(T, {MostName, MostCount})
	end;
most_freq_func([], {_MostName, _MostCount}=T) -> T.

mod_count() ->
	mod_count(mod_list(), 0).
mod_count([_H|T], Count) ->
	mod_count(T, Count + 1);
mod_count([], Count) -> Count.

