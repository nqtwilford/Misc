//Vendor-supplied class header
#ifndef VENDOR_H_
#define VENDOR_H_

class Vendor
{
public:
	virtual void v() const;
	void f() const;	//���麯��
	~Vendor();	//��ƴ���������������
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
