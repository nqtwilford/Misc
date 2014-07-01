#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Test
{
public:
	explicit Test(int i): _i(i){}
	void Show1() const
	{
		cout<<_i<<"\n";
	}
	void Show2(int i)
	{
		cout<<_i<<" and "<<i<<"\n";
	}
	void Show3(int i1, int i2)
	{
		cout<<_i<<" and "<<i1<<" and "<<i2<<"\n";
	}
private:
	int _i;
};

//两个参数的成员函数适配器
template <typename ResultType, typename ObjectType, typename Arg1Type, typename Arg2Type>
class my_mem_fun2_t
{
public:
	typedef ResultType (ObjectType::*MemFuncType)(Arg1Type, Arg2Type);
	typedef ResultType result_type;
	typedef ObjectType * first_argument_type;
	typedef Arg1Type second_argument_type;
	typedef Arg2Type third_argument_type;
public:
	my_mem_fun2_t(MemFuncType memFunc):
	_pMemFunc(memFunc){}
	ResultType operator ()(ObjectType *pObj, Arg1Type arg1, Arg2Type arg2)
	{
		return (pObj->*_pMemFunc)(arg1, arg2);
	}
private:
	MemFuncType _pMemFunc;
};

//生成对应两个参数的成员函数适配器(由于无法从构造函数推导类模版的参数，所以通过一个函数中转)
template <typename ResultType, typename ObjectType, typename Arg1Type, typename Arg2Type>
inline my_mem_fun2_t<ResultType, ObjectType, Arg1Type, Arg2Type>
mem_fun(ResultType (ObjectType::*memFunc)(Arg1Type, Arg2Type) )
{
	return my_mem_fun2_t<ResultType, ObjectType, Arg1Type, Arg2Type>(memFunc);
}

//绑定2,3参数
template <typename FuncType, typename Arg2Type, typename Arg3Type>
class bind2nd3rd_t
{
public:
	bind2nd3rd_t(FuncType func, Arg2Type arg2, Arg3Type arg3):
	_func(func), _arg2(arg2), _arg3(arg3){}
	typename FuncType::result_type operator()(typename FuncType::first_argument_type arg1)
	{
		return _func(arg1, _arg2, _arg3);
	}
private:
	FuncType _func;
	Arg2Type _arg2;
	Arg2Type _arg3;
};

//生成绑定器
template <typename FuncType, typename Arg2Type, typename Arg3Type>
inline bind2nd3rd_t<FuncType, Arg2Type, Arg3Type>
bind2nd3rd(FuncType func, Arg2Type arg2, Arg3Type arg3)
{
	return bind2nd3rd_t<FuncType, Arg2Type, Arg3Type>(func, arg2, arg3);
}

int main(int argc, char **argv)
{
	vector<Test *> vec;
	vec.push_back(new Test(1));
	vec.push_back(new Test(2));
	vec.push_back(new Test(3));
	for_each(vec.begin(), vec.end(), mem_fun(&Test::Show1));
	for_each(vec.begin(), vec.end(), bind2nd(mem_fun(&Test::Show2), 10));
	mem_fun(&Test::Show2)(new Test(4), 13);
	//自己写适配两个参数的适配器，GCC无法完成模板参数推断，VC可以
	mem_fun(&Test::Show3)(new Test(5), 100, 200);
	for_each(vec.begin(), vec.end(), bind2nd3rd(mem_fun(&Test::Show3), 12, 20) );
	return EXIT_SUCCESS;
}
