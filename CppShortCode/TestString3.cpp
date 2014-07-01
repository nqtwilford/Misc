#include "String3.h"

int main()
{
//	String *str = MakeString("Hello");
	String *str = String::Make("Hello");
	cout<<*str<<endl;
	const char *chars = *str;
	cout<<chars<<endl;
	const char *chars2 = str->str();
	cout<<chars<<endl;
}
