//��Ҫ�����������е����Լ��ĳ�Ա�����������ܼ�ӵ�����һ�����麯��
//��Ϊ������ڸ���֮ǰ���٣����Դ�ʱ�����Ѿ������ڣ����µ����˸���Ĵ��麯��
#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(){}
	~Parent()
	{
//		ClearAll();
		ThePure();	//���������Լ���ֱ�ӵĵ��ã������ܼ�����ӵĵ���
	}
	void ClearAll()
	{
		ThePure();
	}
	virtual bool ThePure() = 0;
};

class Child: public Parent
{
public:
	Child()
	{
	}
	~Child()
	{
	}
	virtual bool ThePure()
	{
		return true;
	}
};

int main(int argc, char **args)
{
	Child c;
}
