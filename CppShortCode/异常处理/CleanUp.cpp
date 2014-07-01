#include <iostream>
using namespace std;

ostream &out = cout;

class Noisy
{
public:
	Noisy(const char *nm = "array elem") 
	throw(int)
	{
		objnum = i++;
		memset(name, 0, SIZE);
		strncpy(name, nm, SIZE - 1);
		out<<"constructing noisy "<<objnum
			<<" name ["<<name<<"]"<<endl;
		if(objnum == 5) throw int(5);
		//Not in exception specification
		if(*nm == 'z') throw char('z');
	}
	~Noisy()
	{
		out<<"destructing noisy "<<objnum
			<<" name ["<<name<<"]"<<endl;
	}
	void *operator new[](size_t sz)
	{
		out<<"Noisy::new[]"<<endl;
		return ::new char[sz];
	}
	void operator delete[](void *p)
	{
		out<<"Noisy::delete[]"<<endl;
		::delete [](char *)p;
	}
private:
	static int i;
	int objnum;
	static const int SIZE = 40;
	char name[SIZE];
};
int Noisy::i = 0;

void unexpected_rethrow()
{
	out<<"inside unexpected_rethrow()"<<endl;
	throw 1;	//抛出声明过的异常则可以被捕获
//	throw;	//再重新抛出同样的异常，
            //还是不能被捕获，此处需要在VC中测试
}

int main()
{
	set_unexpected(unexpected_rethrow);
	try
	{
		Noisy n1("before array");
		//Throws exception:
		Noisy *array = new Noisy[7];
		Noisy n2("after array");
	}
	catch (int i)
	{
		out<<"caught "<<i<<endl;
	}

	out<<"testing unexpected:"<<endl;
	try
	{
		Noisy n3("before unexpected");
		Noisy n4("z");
		Noisy n5("after unexpected");
	}
	catch (char c)
	{
		out<<"caught "<<c<<endl;
	}
	catch(...)
	{
		out<<"caught other"<<endl;
	}
}
