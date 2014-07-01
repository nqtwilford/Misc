/*实际就是一种工厂模式
*/
#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
	enum Type {CIRCLE, SQUARE, TRIANGLE};
	virtual void Draw() = 0;
	virtual ~Shape(){cout<<"~Shape()"<<endl;}
	static Shape *make(Type);
protected:
	Shape(){}
private:
	Shape(const Shape &);
};

class Circle : public Shape
{
public:
	void Draw(){cout<<"Circle::Draw()"<<endl;}
	~Circle(){cout<<"~Circle"<<endl;}
	friend Shape *Shape::make(Type);
protected:
	Circle(){}
private:
	Circle(const Circle &);
	Circle &operator=(const Circle &);
};

class Square : public Shape
{
public:
	void Draw(){cout<<"Square::Draw()"<<endl;}
	~Square(){cout<<"~Square"<<endl;}
	friend Shape *Shape::make(Type);
protected:
	Square(){}
private:
	Square(const Square &);
	Square &operator=(const Square &);
};

class Triangle : public Shape
{
public:
	void Draw(){cout<<"Triangle::Draw()"<<endl;}
	~Triangle(){cout<<"~Triangle"<<endl;}
	friend Shape *Shape::make(Type);
protected:
	Triangle(){}
private:
	Triangle(const Triangle &);
	Triangle &operator=(const Triangle &);
};

Shape *Shape::make(Type t)
{
	Shape *s = 0;
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
	s->Draw();
	return s;
}

int main(int argc, char *argv[])
{
	vector<Shape *> shapes;
	cout<<"Virtual constructor calls:"<<endl;
	shapes.push_back(Shape::make(Shape::CIRCLE));
	shapes.push_back(Shape::make(Shape::SQUARE));
	shapes.push_back(Shape::make(Shape::TRIANGLE));
	cout<<"Virtual function calls:"<<endl;
	for(vector<Shape *>::iterator iter =
		shapes.begin(); iter != shapes.end(); ++iter)
	{
		(*iter)->Draw();
		delete (*iter);
	}
	return 0;
}
