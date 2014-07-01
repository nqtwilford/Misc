#include <iostream>
#include <string>
using namespace std;

class Obj
{
public:
	void f()
	{
		cout<<i++<<endl;
	}
	void g()
	{
		cout<<j++<<endl;
	}
private:
	static int i, j;
};

int Obj::i = 47;
int Obj::j = 11;

class Obj_container
{
public:
	Obj_container():index(0)
	{
		memset(objs, 0, size*sizeof(Obj *));
	}
	void add(Obj *obj)
	{
		if(index >= size) return;
		objs[index++] = obj;
	}
	friend class SmartPtr;
private:
	static const int size = 100;
	Obj *objs[size];
	int index;
};

class SmartPtr
{
public:
	SmartPtr(Obj_container *oc):index(0),oc(oc){}
	//return value indicates end of list
	int operator++()
	{
		if(index >= oc->size) return 0;
		if(oc->objs[++index] == 0) return 0;
		return 1;
	}
	int operator++(int)
	{
		return operator++();
	}
	Obj *operator->() const
	{
		if(oc->objs[index]) return oc->objs[index];
		static Obj dummy;
		return &dummy;
	}
private:
	Obj_container *oc;
	int index;
};

int main()
{
	const int size = 10;
	Obj objs[size];
	Obj_container oc;
	for (int i = 0; i < size; ++i)
	{
		oc.add(&objs[i]);
	}
	SmartPtr sp(&oc);
	do
	{
		sp->f();
		sp->g();
	}
	while (sp++);
}
