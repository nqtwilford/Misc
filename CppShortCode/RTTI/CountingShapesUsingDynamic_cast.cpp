/*------------------------------------
随机产生一些对象，使用3种方法统计对象个数
1.构造函数中累加静态变量统计
2.使用dynamic_cast进行运行时类型检查
3.使用typeid运行时检查类型
------------------------------------*/
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class Shape
{
public:
	Shape(){++count;}
	virtual ~Shape() = 0;
	virtual void Draw() const = 0;
	static int Quantity() {return count;}
protected:
	static int count;
};

int Shape::count = 0;

Shape::~Shape(){--count;}

class Rectangle : public Shape
{
public:
	Rectangle(){++count;}
	Rectangle(const Rectangle &){++count;}
	virtual ~Rectangle(){--count;}
	virtual void Draw() const
	{
		cout<<"Rectangle::Draw()"<<endl;
	}
	static int Quantity() {return count;}
protected:
	static int count;
private:
	void operator=(Rectangle &);
};

int Rectangle::count = 0;

class Ellipse : public Shape
{
public:
	Ellipse(){++count;}
	Ellipse(const Ellipse &){++count;}
	virtual ~Ellipse(){--count;}
	virtual void Draw() const
	{
		cout<<"Ellipse::Draw()"<<endl;
	}
	static int Quantity() {return count;}
protected:
	static int count;
private:
	void operator=(Ellipse &);
};

int Ellipse::count = 0;

class Circle : public Ellipse
{
public:
	Circle(){++count;}
	Circle(const Circle &){++count;}
	virtual ~Circle(){--count;}
	virtual void Draw() const 
	{
		cout<<"Circle::Draw()"<<endl;
	}
	static int Quantity() {return count;}
protected:
	static int count;
private:
	void operator=(Circle &);
};

int Circle::count = 0;

int main()
{
	vector<Shape *> shapes;
	srand( (unsigned)time( NULL ) );
	const int mod = 12;
	for (int i = 0; i < rand() % mod; ++i)
	{
		shapes.push_back(new Rectangle);
	}
	for (int i = 0; i < rand() % mod; ++i)
	{
		shapes.push_back(new Ellipse);
	}
	for (int i = 0; i < rand() % mod; ++i)
	{
		shapes.push_back(new Circle);
	}

	//dynamic_cast统计
	int nCircles = 0;
	int nEllipses = 0;
	int nRects = 0;
	int nShapes = 0;

	//typeid统计
	int nCircles1 = 0;
	int nEllipses1 = 0;
	int nRects1 = 0;
	int nShapes1 = 0;

	for(vector<Shape *>::const_iterator iter = shapes.begin();
		iter != shapes.end(); ++iter)
	{
		(*iter)->Draw();
		//dynamic_cast统计
		if(dynamic_cast<Circle *>(*iter) != NULL)
		{
			++nCircles;
		}
		if(dynamic_cast<Ellipse *>(*iter) != NULL)
		{
			++nEllipses;
		}
		if(dynamic_cast<Rectangle *>(*iter) != NULL)
		{
			++nRects;
		}
		if(dynamic_cast<Shape *>(*iter) != NULL)
		{
			++nShapes;
		}
		//typeid统计
		if(typeid(**iter) == typeid(Circle))
		{
			++nCircles1;
			++nEllipses1;
			++nShapes1;
		}
		if(typeid(**iter) == typeid(Ellipse))
		{
			++nEllipses1;
			++nShapes1;
		}
		if(typeid(**iter) == typeid(Rectangle))
		{
			++nRects1;
			++nShapes1;
		}
		if(typeid(**iter) == typeid(Shape))
		{
			++nShapes1;
		}
	}

	cout<<endl<<endl
		<<"Circle = "<<nCircles<<endl
		<<"Ellipse = "<<nEllipses<<endl
		<<"Rectangles = "<<nRects<<endl
		<<"Shapes = "<<nShapes<<endl
		<<endl
		<<"Circle1 = "<<nCircles1<<endl
		<<"Ellipse1 = "<<nEllipses1<<endl
		<<"Rectangles1 = "<<nRects1<<endl
		<<"Shapes1 = "<<nShapes1<<endl
		<<endl
		<<"Circle::Quan = "<<Circle::Quantity()<<endl
		<<"Ellipse::Quan = "<<Ellipse::Quantity()<<endl
		<<"Rectangle::Quan = "<<Rectangle::Quantity()<<endl
		<<"Shape::Quan ="<<Shape::Quantity()<<endl;
}
