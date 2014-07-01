//���ܣ��������������е�#�ַ��Ƶ��ַ���β��
//�������ƣ�ChangeToTail
//��ڲ�����pSZָ�򻺳�����ָ��,   nSize����������
//���ڣ�pSZ��ָ�������е�#�ַ����Ƶ�������β��
//����ֵ���ڳ��ڻ������е�һ��#��λ��,������������#�ַ��򷵻�-1
//˵�����紫��#W#W#W#WW#��   10   �򴫳�ʱӦת��ΪWWWWW#####���ҷ���ֵΪ5 

#include <iostream>
using namespace std;

int ChangeToTail(char *pSZ, int nSize)
{
	bool hasSharp = false;
	int tail = nSize - 1;
	for(int i = 0; i < tail; ++i)
	{
		if(pSZ[i] == '#')
		{
			hasSharp = true;
			while(pSZ[tail] == '#' & tail > i)
			{
				--tail;
			}
			pSZ[i] = pSZ[tail];
			pSZ[tail] = '#';
		}
	}
	return hasSharp ? tail : -1;
}

int main()
{
	char buf[] = "wilford";
	int pos = ChangeToTail(buf, sizeof(buf) - 1);
	cout<<buf<<"\t"<<pos<<endl;
	return 0;
}
