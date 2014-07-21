-module(myfile).
-export([read_file/1]).

read_file(File) ->
	case file:read_file(File) of
		{ok, Bin} -> Bin;
		{error, Why} -> throw({fileReadError, Why})
	end.
