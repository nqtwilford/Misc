//通过RTTI垃圾分类收集
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

ostream &out = cout;

class Trash
{
public:
	Trash(float wt) : m_fWeight(wt){}
	virtual float value() const = 0;
	float weight() const {return m_fWeight;}
	virtual ~Trash(){}
private:
	float m_fWeight;
};

class Aluminum : public Trash
{
public:
	Aluminum(float wt) : Trash(wt){}
	float value() const {return m_fVal;}
	static void value(int newval){m_fVal = newval;}
private:
	static float m_fVal;
};

float Aluminum::m_fVal = 1.67f;

class Paper : public Trash
{
public:
	Paper(float wt) : Trash(wt){}
	float value() const {return m_fVal;}
	static void value(int newval){m_fVal = newval;}
private:
	static float m_fVal;
};

float Paper::m_fVal = 0.10f;

class Glass : public Trash
{
public:
	Glass(float wt) : Trash(wt){}
	float value() const {return m_fVal;}
	static void value(int newval){m_fVal = newval;}
private:
	static float m_fVal;
};

float Glass::m_fVal = 0.23f;

//Sums up the value of the trash in a bin
template<class T>
void SumValue(const vector<T> &bin, ostream &os)
{
	float val = 0;
	for(typename vector<T>::const_iterator 
		iter = bin.begin();
		iter != bin.end(); ++iter)
	{
		val += (*iter)->weight()*(*iter)->value();
		os<<"weight of "<<typeid(**iter).name()
			<<" = "<<(*iter)->weight()<<endl;
	}
	os<<"Total value = "<<val<<endl;
}

int main()
{
	srand((unsigned)time(NULL));
	vector<Trash *> bin;
	for(int i = 0; i < 30; ++i)
	{
		switch(rand() % 3)
		{
		case 0:
			bin.push_back(new Aluminum(rand() % 100));
			break;
		case 1:
			bin.push_back(new Paper(rand() % 100));
			break;
		case 2:
			bin.push_back(new Glass(rand() % 100));
			break;
		}
	}
	vector<Glass *> glassbin;
	vector<Paper *> paperbin;
	vector<Aluminum *> albin;
	for(vector<Trash *>::iterator iter =
		bin.begin(); iter != bin.end(); ++iter)
	{
		Aluminum *ap = 
			dynamic_cast<Aluminum *>(*iter);
		Paper *pp = 
			dynamic_cast<Paper *>(*iter);
		Glass *gp = 
			dynamic_cast<Glass *>(*iter);
		if(ap) albin.push_back(ap);
		if(pp) paperbin.push_back(pp);
		if(gp) glassbin.push_back(gp);
	}
	SumValue(albin, out);
	SumValue(paperbin, out);
	SumValue(glassbin, out);
	SumValue(bin, out);
}
