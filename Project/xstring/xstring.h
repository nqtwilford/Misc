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

static const char masksUtf8[6] = {
	(char)0x80, //10000000
	(char)0xE0, //11100000
	(char)0xF0, //11110000
	(char)0xF8, //11111000
	(char)0xFC, //11111100
	(char)0xFE, //11111110
};

static const int bitNums[6] = {
	7, 11, 16, 21, 26, 31,
};

static const int masksUnicode[6] = {
	(int)(0xFFFFFFFFu >> (32 - bitNums[0])),
	(int)(0xFFFFFFFFu >> (32 - bitNums[1])),
	(int)(0xFFFFFFFFu >> (32 - bitNums[2])),
	(int)(0xFFFFFFFFu >> (32 - bitNums[3])),
	(int)(0xFFFFFFFFu >> (32 - bitNums[4])),
	(int)(0xFFFFFFFFu >> (32 - bitNums[5])),
};

size_t getByteNumFromUtf8(char byte)
{
	for(size_t i = 0; i < 6; ++i)
	{
		char mask = masksUtf8[i];
		if((byte & mask) == (char)(mask<<1))
		{
			return i + 1;
		}
	}
	//not utf8 encoding
	assert(false);
	return 0;
}

size_t getByteNumFromUnicode(int code)
{
	//printf("code: 0x%04X ", code);
	for(size_t i = 0; i < 6; ++i)
	{
		//printf("masked: 0x%04X ", code & ~masksUnicode[i]);
		if((code & ~masksUnicode[i]) == 0)
			return i + 1;
	}
	//not unicode
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
		size_t byteNum = getByteNumFromUtf8(byte);
		for(size_t j = 0; j < byteNum; ++j)
		{
			char currByte = utf8str[i + j];
			//not utf8 encoding
			assert(j == 0 || (currByte & 0xC0) == 0x80);
			size_t shiftNum = j == 0 ? 0 : 6;
			wchar = wchar << shiftNum;
			wchar |= currByte & (j == 0 ? ~masksUtf8[j] : 0x3F);
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

std::string wstringToUtf8(const wchar_t *wstr)
{
	std::string result;
	size_t i = 0;
	int c = '\0';
	while((c = wstr[i]))
	{
		size_t byteNum = getByteNumFromUnicode(c);
		printf("byteNum:%d\n", byteNum);
		if(byteNum == 1)
			result.push_back((char)c);
		else
		{
			for(size_t j = 0; j < byteNum; ++j)
			{
				char byteHead = j == 0 ? masksUtf8[byteNum-1]<<1 : (char)0x80;
				int shiftNum = 6*(byteNum-j-1);
				char byteTail = (c >> shiftNum) & 0x3F;
				char byte = byteHead | byteTail;
				printf("head:%02X shiftNum:%d tail:%02X byte:%02X\n", byteHead, shiftNum, byteTail, byte);
				result.push_back(byte);
			}
		}
		++i;
	}
	return result;
}

std::string wstringToUtf8(std::wstring wstr)
{
	return wstringToUtf8(wstr.c_str());
}

