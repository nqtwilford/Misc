#include <iostream>
using namespace std;

class Framis
{
public:
	Framis()
	{
		cout<<"Framis()"<<endl;
	}
	~Framis()
	{
		cout<<"~Framis()"<<endl;
	}
	void *operator new(size_t sz) throw();
	void operator delete(void *);
private:
	char c[10];
	static const int psize = 100;
	static unsigned char pool[];
	static bool alloc_map[];
};
unsigned char Framis::pool[psize*sizeof(Framis)];
bool Framis::alloc_map[psize] = {0};

void *Framis::operator new(size_t sz) throw()
{
	for(int i = 0; i < psize; ++i)
	{
		if(!alloc_map[i])
		{
			cout<<"using block "<<i<<" ... "<<endl;
			alloc_map[i] = true;
			return pool + (i*sizeof(Framis));
		}
	}
	cout<<"out of memory"<<endl;
	return NULL;
}

void Framis::operator delete(void *m)
{
	if(m == NULL) return;
	unsigned long block = (unsigned long)m -
		                  (unsigned long)pool;
	block /= sizeof(Framis);
	cout<<"freeing block: "<<block<<endl;
	alloc_map[block] = false;
}

int main()
{
//	int *pint = new int;
//	delete pint;
//	Framis *p1 = new Framis;
//	Framis *p2 = new Framis;
//	delete p1;
//	Framis *p3 = new Framis;
//	delete p3;
//	delete p2;
//	cout<<"------"<<endl;
//	Framis *ps[101];	//the last one will out of memory
//	for (int i = 0; i < 101; ++i)
//	{
//		ps[i] = new Framis;
//	}
//	for (int i = 0; i < 101; ++i)
//	{
//		delete ps[i];
//	}
	Framis *ps2 = new Framis[3];
	delete ps2;		//causing crash, ps2 was allocated in heap, not in our own pool
	return 0;
}
