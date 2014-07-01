#pragma once

#include <assert.h>
#include <iostream>
using namespace std;

struct static_tag{};
struct const_tag{};
struct dynamic_tag{};

static void TRUE_SUBST(){}
typedef void (*BOOL_SUBST)();

class ref_count_base
{
public:
	ref_count_base():_ref(1){}
	virtual ~ref_count_base()
	{
	}
	ref_count_base &operator++()
	{
		++_ref;
		return *this;
	}
	ref_count_base &operator--()
	{
		--_ref;
		return *this;
	}
	operator unsigned int ()
	{
		return _ref;
	}

	virtual void release(){}

protected:
	unsigned int _ref;
};

template <typename T>
class ref_count_obj : public ref_count_base
{
public:
	ref_count_obj(T *p):_p(p){}
	virtual void release()
	{
		delete _p;
	}
protected:
	T *_p;
};

template <typename T>
class my_shared_ptr
{
public:
	my_shared_ptr():
		_object(nullptr),
		_ref(nullptr)
	{cout<<"null con"<<endl;}

	my_shared_ptr(T *obj):
		_object(obj),
		_ref(nullptr)
	{
		cout<<"obj con"<<endl;
		if(obj)
			_ref = new ref_count_obj<T>(obj);
	}

	//如果不提供一个默认的拷贝构造函数，系统将会自动生成一个，而不会去使用那个模板化的拷贝构造函数
	my_shared_ptr(const my_shared_ptr<T> &other):
		_object(other._object),
		_ref(other._ref)
	{
		cout<<"Default copy con"<<endl;
		++(*_ref);
	}

	//auto up-cast
	template <typename U>
	my_shared_ptr(const my_shared_ptr<U> &other):
		_object(other._object),
		_ref(other._ref)
	{
		cout<<"Templated copy con"<<endl;
		++(*_ref);
	}

	template <typename U>
	my_shared_ptr(const my_shared_ptr<U> &other, const dynamic_tag &):
		_object(dynamic_cast<T *>(other._object)),
		_ref(other._ref)
	{
		cout<<"Templated copy con with dynamic_cast"<<endl;
		++(*_ref);
	}

	~my_shared_ptr()
	{
		if(!_ref) return;
		cout<<"Destruct:curr ref:"<<*_ref<<endl;
		assert(ref_count() >= 1);
		if(--(*_ref) == 0)
		{
			//delete _object;
			//destroy();
			_ref->release();
			delete _ref;
		}
	}
private:
	//void destroy()
	//{
	//	delete _object;
	//}

	unsigned int ref_count() const
	{
		return _ref ? *_ref : 0;
	}

	T *operator->()
	{
		return _object;
	}

	const T *operator->() const
	{
		return _object;
	}

	T &operator*()
	{
		return *_object;
	}

	const T &operator*() const
	{
		return *_object;
	}

	operator BOOL_SUBST() const
	{
		cout<<"operator bool()"<<endl;
		return (_object != nullptr ? TRUE_SUBST : 0);
	}
private:
	
	T *_object;
	ref_count_base *_ref;

	template <typename U>
	friend class my_shared_ptr;
};

template <typename T, typename U>
my_shared_ptr<T> dynamic_ptr_cast(const my_shared_ptr<U> &value)
{
	return my_shared_ptr<T>(value, dynamic_tag());
}
//static_cast const_cast同理

#include "boost/shared_ptr.hpp"
//#define sptr std::shared_ptr
#define sptr my_shared_ptr
//#define sptr boost::shared_ptr
