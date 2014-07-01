#include <iostream>
using namespace std;

class Shape
{
public:
	virtual void Draw(){};
};

class Circle : public Shape
{
public:
	virtual void Draw(){}
};

class Triangle : public Shape
{
public:
	virtual void Draw(){}
};

int main()
{
	Shape *p1 = new Triangle;
	Shape *p2 = new Shape;
	Shape *p3 = new Circle;
	Triangle *pT1 = dynamic_cast<Triangle *>(p1);
	if(pT1 != NULL)
	{
		cout<<"p1 is a Triangle"<<endl;
	}
	else
	{
		cout<<"p1 is not a Triangle"<<endl;
	}

	Circle *pC1 = dynamic_cast<Circle *>(p2);
	if(pC1 != NULL)
	{
		cout<<"p2 is a Circle"<<endl;
	}
	else
	{
		cout<<"p2 is not a Circle"<<endl;
	}
	delete p3;
	delete p2;
	delete p1;
}
