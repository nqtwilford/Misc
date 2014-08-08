-module(lib_find).
-export([files/3, files/5]).
-import(lists, [reverse/1]).

-include_lib("kernel/include/file.hrl").

files(Dir, Wildcard, Recursive) ->
	RegEx = xmerl_regexp:sh_to_awk(Wildcard),
	reverse(files(Dir, RegEx, Recursive, fun(File, Acc) -> [File|Acc] end, [])).

files(Dir, RegEx, Recursive, Fun, Acc) ->
	case file:list_dir(Dir) of
		{ok, Files} -> find_files(Files, Dir, RegEx, Recursive, Fun, Acc);
		{error, _} -> Acc
	end.

find_files([File|T], Dir, RegEx, Recursive, Fun, Acc0) ->
	FullName = filename:join([Dir, File]),
	%io:format("matching file:~p~n", [FullName]),
	case file_type(FullName) of
		regular ->
			case re:run(FullName, RegEx, [{capture, none}]) of
				match ->
					Acc = Fun(FullName, Acc0),
					find_files(T, Dir, RegEx, Recursive, Fun, Acc);
				nomatch ->
					find_files(T, Dir, RegEx, Recursive, Fun, Acc0)
			end;
		directory ->
			case Recursive of
				true ->
					Acc1 = files(FullName, RegEx, Recursive, Fun, Acc0),
					find_files(T, Dir, RegEx, Recursive, Fun, Acc1);
				false ->
					find_files(T, Dir, RegEx,  Recursive, Fun, Acc0)
			end;
		error ->
			find_files(T, Dir, RegEx, Recursive, Fun, Acc0)
	end;
find_files([], _, _, _, _, A) ->
	A.

file_type(File) ->
	case file:read_file_info(File) of
		{ok, Facts} ->
			case Facts#file_info.type of
				regular -> regular;
				directory -> directory;
				_ -> error
			end;
		_ ->
			error
	end.
