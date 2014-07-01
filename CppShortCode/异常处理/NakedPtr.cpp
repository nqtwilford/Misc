#include <iostream>
using namespace std;

ostream &out = cout;

class Bonk
{
public:
	Bonk(){out<<"Bonk()"<<endl;}
	~Bonk(){out<<"~Bonk()"<<endl;}
};

class OG
{
public:
	void *operator new(size_t sz)
	{
		out<<"allocating an og"<<endl;
		throw int(47);
		//return 0;
	}
	void operator delete(void *p)
	{
		out<<"deallocating an og"<<endl;
		::delete (char *)p;	//�Ƿ�����ͷ������пռ���?�ǵ�
	}
};

class UseResources
{
public:
	UseResources(int count = 1)
	{
		out<<"UseResource()"<<endl;
		bp = new Bonk[count];
		op = new OG;	//�쳣���Զ����ϲ��׳�
	}
	~UseResources()
	{
		out<<"~UseResource()"<<endl;
		delete []bp;
		delete op;
	}
private:
	Bonk *bp;
	OG *op;
};

int main()
{
//	try
	{
		UseResources ur(3);
	}
//	catch (int)
//	{
//		out<<"inside handler"<<endl;
//	}
}
