#ifndef STACK_H_
#define STACK_H_
template <class T>
class Stack
{
public:
	Stack(): top(0){}
	bool Push(const T &t)
	{
		if(top >= size) return false;
		arr[top++] = t;
		return true;
	}
	bool Pop(T *pt)
	{
		if(top <= 0) return false;
		*pt = arr[--top];
		return true;
	}
private:
	static const int size = 5;
	T arr[size];
	int top;
};
#endif
