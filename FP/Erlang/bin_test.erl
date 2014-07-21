-module(bin_test).
-export([byte_reverse/1,
		 bit_reverse/1,
		 term_to_packet/1,
		 packet_to_term/1, 
		 test_byte_reverse/0,
		 test_bit_reverse/0,
		 test_packet/0]).

byte_reverse(<<>>) -> <<>>;
byte_reverse(<<Byte:8, RestBin/binary>>) ->
	RestReverse = byte_reverse(RestBin),
	<<RestReverse/binary, Byte:8>>.

test_byte_reverse() ->
	byte_reverse(<<"abcd">>).

bit_reverse(<<>>) -> <<>>;
bit_reverse(<<Bit:1, RestBin/bitstring>>) ->
	RestReverse = bit_reverse(RestBin),
	<<RestReverse/bitstring, Bit:1>>.

test_bit_reverse() ->
	bit_reverse(<<2#101011000111:12>>).

term_to_packet(Term) -> 
	Bin = term_to_binary(Term),
	Size = byte_size(Bin),
	<<Size:32/integer, Bin/binary>>.

packet_to_term(<<Size:32/integer, Bin/binary>>) ->
	case Size =:= byte_size(Bin) of
		true -> binary_to_term(Bin);
		false -> error(packetError)
	end.

test_packet() ->
	packet_to_term(term_to_packet(#{name => zhangwei, age => 27})).
