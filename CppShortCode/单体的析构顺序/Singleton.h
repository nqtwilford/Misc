#ifndef SINGLETON_H_
#define SINGLETON_H_
template <class T>
class Singleton
{
public:
//	static T &Instance()	
//	{
//		static T t;
//		return t;
//	}
/*为什么不使用上面的方式？
**处于函数中的静态对象，只会在函数第一次调用的时候创建，
**无法保证构造函数中的初始化操作第一时间执行
**而成员静态对象则会在main函数之前创建
*/
	inline static T &Instance()
	{
		return t;
	}
private:
	static T t;
};

template <class T>
T Singleton<T>::t;
#endif
