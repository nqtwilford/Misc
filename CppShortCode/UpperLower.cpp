#include <iostream>
using namespace std;

class bin
{
public:
	bin(int i, int length = 8):i(i),length(length){}
	friend ostream &operator <<(ostream &os, const bin &b)
	{
		for(int i = b.length - 1; i >= 0; --i)
		{
			int j = b.i>>i & 0x0001;
			os<<j;
		}
		return os;
	}
protected:
	int i;
	int length;
};

char toupper(char c)
{
	return c & 0xdf;
}

char tolower(char c)
{
	return c | 0x20;
}

char reverse(char c)
{
	return c ^ 0x20;
}

void ReverseCase(char *str)
{
	for(int i = 0; str[i] != '\0'; ++i)
	{
		str[i] = str[i] ^ 0x20;
	}
}

int main(int argc, char **argv)
{
	cout<<tolower('M')<<endl;
	cout<<toupper('f')<<toupper('J')<<tolower('T')<<tolower('u')<<endl;
	cout<<reverse('z')<<reverse('S')<<endl;
	char str[] = "ZhangWei";
	ReverseCase(str);
	cout<<str<<endl;
	return EXIT_SUCCESS;
}
