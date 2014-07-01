/*如果某个虚函数在子类中没有被重定义，
**或者子类显式调用父类的虚函数，都会
**导致父类函数被调用，而在父类函数中又
**会调用成员s的函数，而成员s=0
*/
#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
	enum Type {CIRCLE, SQUARE, TRIANGLE};
	Shape(Type);	//"Virtual" constructor
	virtual void Draw(){s->Draw();}
	virtual ~Shape()
	{
		cout<<"~Shape()"<<endl;
		delete s;
		s = 0;
	}
protected:
	Shape():s(0){}
private:
	Shape(const Shape &);
	Shape &operator=(const Shape &);
	Shape *s;
};

class Circle : public Shape
{
public:
	Circle(){}
	void Draw()
	{
		cout<<"Circle::Draw()"<<endl;
	}
	~Circle(){cout<<"~Circle"<<endl;}
private:
	Circle(const Circle &);
	Circle &operator=(const Circle &);
};

class Square : public Shape
{
public:
	Square(){}
	void Draw()
	{
		cout<<"Square::Draw()"<<endl;
	}
	~Square(){cout<<"~Square"<<endl;}
private:
	Square(const Square &);
	Square &operator=(const Square &);
};

class Triangle : public Shape
{
public:
	Triangle(){}
	void Draw()
	{
		cout<<"Triangle::Draw()"<<endl;
	}
	~Triangle(){cout<<"~Triangle"<<endl;}
private:
	Triangle(const Triangle &);
	Triangle &operator=(const Triangle &);
};

Shape::Shape(Type t)
{
	switch(t)
	{
	case CIRCLE:
		s = new Circle;
		break;
	case SQUARE:
		s = new Square;
		break;
	case TRIANGLE:
		s = new Triangle;
		break;
	}
	Draw();
}

int main(int argc, char *argv[])
{
	vector<Shape *> shapes;
	cout<<"Virtual constructor calls:"<<endl;
	shapes.push_back(new Shape(Shape::CIRCLE));
	shapes.push_back(new Shape(Shape::SQUARE));
	shapes.push_back(new Shape(Shape::TRIANGLE));
//	cout<<"Virtual function calls:"<<endl;
//	for(vector<Shape *>::iterator iter =
//		shapes.begin(); iter != shapes.end(); ++iter)
//	{
//		(*iter)->Draw();
//	}
	Shape c(Shape::CIRCLE);
	return 0;
}
