#include <string>
#include <assert.h>
#include <stdio.h>

#ifdef _T
#undef _T
#endif

#ifdef UNICODE
#define _T(X) L##X
#else
#define _T(X) X
#endif

static const char masks[6] = {
	(char)0x80, //10000000
	(char)0xE0, //11100000
	(char)0xF0, //11110000
	(char)0xF8, //11111000
	(char)0xFC, //11111100
	(char)0xFE, //11111110
};

size_t getByteNum(char byte)
{
	for(size_t i = 0; i < 6; ++i)
	{
		char mask = masks[i];
		if((byte & mask) == (char)(mask<<1))
		{
			return i + 1;
		}
	}
	//not utf8 encoding
	assert(false);
	return 0;
}

std::wstring utf8ToWString(const char *utf8str)
{
	std::wstring result;
	size_t i = 0;
	char byte = '\0';
	while((byte = utf8str[i]))
	{
		wchar_t wchar = L'\0';
		size_t byteNum = getByteNum(byte);
		for(size_t j = 0; j < byteNum; ++j)
		{
			char currByte = utf8str[i + j];
			//not utf8 encoding
			assert(j == 0 || (currByte & 0xC0) == 0x80);
			size_t shiftNum = j == 0 ? 0 : 6;
			wchar = wchar << shiftNum;
			wchar |= currByte & (j == 0 ? ~masks[j] : 0x3F);
			printf("j:%d currByte:%02X shiftNum:%d wchar:%04X\n", j, (unsigned char)currByte, shiftNum, (unsigned int)wchar);  
		}
		result.push_back(wchar);
		i += byteNum;
	}
	return result;
}

std::wstring utf8ToWString(std::string utf8str)
{
	return utf8ToWString(utf8str.c_str());
}
