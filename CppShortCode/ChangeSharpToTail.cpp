//功能：将给定缓冲区中的#字符移到字符串尾部
//函数名称：ChangeToTail
//入口参数：pSZ指向缓冲区的指针,   nSize缓冲区长度
//出口：pSZ所指缓冲区中的#字符被移到缓冲区尾部
//返回值：在出口缓冲区中第一个#的位置,若缓冲区中无#字符则返回-1
//说明：如传入#W#W#W#WW#，   10   则传出时应转换为WWWWW#####并且返回值为5 

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
