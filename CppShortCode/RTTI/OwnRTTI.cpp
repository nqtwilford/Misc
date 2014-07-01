#include <iostream>
#include <vector>
using namespace std;

class One
{
public:
	virtual bool dynamic_type(int ID)
	{
		if(ID == baseID) return true;
		return false;
	}
protected:
	enum{baseID = 1000};
};

class Two1 : public One
{
public:
	virtual bool dynamic_type(int ID)
	{
		if(ID == typeID) return true;
		return One::dynamic_type(ID);
	}
	static Two1 *dynacast(One *p)
	{
		if(p->dynamic_type(typeID))
			return (Two1 *)p;
		return 0;
	}
	virtual void Special()
	{
		cout<<"Special Two1"<<endl;
	}
protected:
	enum{typeID = baseID + 1};
};

class Two2 : public One
{
public:
	virtual bool dynamic_type(int ID)
	{
		if(ID == typeID) return true;
		return One::dynamic_type(ID);
	}
	static Two2 *dynacast(One *p)
	{
		if(p->dynamic_type(typeID))
			return (Two2 *)p;
		return 0;
	}
protected:
	enum{typeID = baseID + 2};
};

class Three : public Two1
{
public:
	virtual bool dynamic_type(int ID)
	{
		if(ID == typeID) return true;
		return Two1::dynamic_type(ID);
	}
	static Three *dynacast(One *p)
	{
		if(p->dynamic_type(typeID))
			return (Three *)p;
		return 0;
	}
protected:
	enum{typeID = baseID + 3};
};

int main(int argc, char *argv[])
{
	vector<One *> vec;
	vec.push_back(new Two1);
	vec.push_back(new Two2);
	vec.push_back(new Three);

	for(vector<One *>::iterator iter = vec.begin();
		iter != vec.end(); ++iter)
	{
		Two1 *p21 = Two1::dynacast(*iter);
		if(p21 != NULL) p21->Special();
		else cout<<"Not a Two1"<<endl;
	}
	
	cout<<"cast from intermediate pointer:"<<endl;
	One *p1 = new Three;
	Two1 *p21 = Two1::dynacast(p1);
	if(p21) cout<<"it's a Two1"<<endl;
	Two2 *p22 = Two2::dynacast(p1);
	if(!p22) cout<<"it's not a Two2"<<endl;
	Three *p3 = Three::dynacast(p1);
	if(p3) cout<<"it's also a Three"<<endl;
	return 0;
}
