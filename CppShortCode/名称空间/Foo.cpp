#include "Foo.h"
#include <iostream>
using namespace std;

//������������������cpp��ʹ�ã�ֻ��Ҫ��������
//���������cpp�ж����������������������ʱ�����ض���
void print1()
{
	cout<<"A function you can access"<<endl;
}

namespace
{
	//������������������ƿռ��У�������cpp���޷�����
	//������Ⱦ����cpp����������
	void print()
	{
		cout<<"A function you can not access"<<endl;
	}
}
namespace wilford
{
	//��print1����
	void print2()
	{
		cout<<"A function you also can access"<<endl;
	}
	void Foo::f()
	{
		print();
	}
}
