#include <iostream>
#include <iterator>
#include <set>
using namespace std;

int main()
{
	//greater�ǱȽ�"����"����������
	set<int, greater<int> > intset;
	multiset<int> intmset;	//ȱʡʹ��С�ڲ�����
	for(int i = 0; i < 25; ++i)
	{
		for(int j = 0; j < 10; ++j)
		{
			intset.insert(j);
			intmset.insert(j);
		}
	}

	copy(intset.begin(), intset.end(),
		ostream_iterator<int>(cout, "\n"));
	copy(intmset.begin(), intmset.end(),
		ostream_iterator<int>(cout, "\n"));
}
