//Vendor-supplied class header
#ifndef VENDOR_H_
#define VENDOR_H_

class Vendor
{
public:
	virtual void v() const;
	void f() const;	//非虚函数
	~Vendor();	//设计错误，析构函数非虚
};

class Vendor1 : public Vendor
{
public:
	virtual void v() const;
	void f() const;
	~Vendor1();
};

void A(const Vendor &);
void B(const Vendor &);
#endif
