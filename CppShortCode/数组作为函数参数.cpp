//����f��g��h��ȫ�ȼۣ�����ĳ��Ȳ�����ͨ���������ݵ������ڲ�
//�β�i�Զ��˻�Ϊָ�룬Ϊ�˱�����ᣬӦֻʹ��ָ����ʽ
//������ʹ��������ʽ���������纯��foo��Ȼ������fooֻ�ܽ���10��Ԫ�ص�int����
//����ģ�壬���Խ���������������飬�纯��bar��
//ͬ��������ģ�壬Ҳ���Խ����������͵�����
#include <iostream>
#include <vector>
using namespace std;

void f(int i[10])
{
	cout<<sizeof(i)<<endl;
}

void g(int i[])
{
	cout<<sizeof(i)<<endl;
}

void h(int *i)
{
	cout<<sizeof(i)<<endl;
}

void foo(const int (&i)[10])
{
	cout<<sizeof(i)<<endl;
}

template<size_t N>
void bar(const int (&i)[N])
{
	cout<<sizeof(i)<<endl;
}

int main(int argc, char *argv[])
{
	int i[5] = {0};
	f(i);
	g(i);
	h(i);
//	foo(i);		//illegal
	int j[10] = {0};
	foo(j);
	int k[6] = {0};
//	foo(k);		//illegal
	bar(k);
	return 0;
}
