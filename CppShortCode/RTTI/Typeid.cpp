#include <iostream>
using namespace std;

class Triangle;
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
	Shape *p1 = new Shape;
	Shape *p2 = new Circle;
	Shape *p3 = new Triangle;
	cout<<typeid(*p2).name()<<endl;
	cout<<typeid(13).name()<<endl;
	//before反映的是定义实现的排列顺序，
	//不是声明顺序，也不是继承层次中的顺序
	cout<<typeid(*p1).before(typeid(*p3))<<endl;
	delete p3;
	delete p2;
	delete p1;
}
