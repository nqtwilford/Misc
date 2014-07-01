#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

class Counted
{
public:
	Counted(const char *ID = "tmp")		//普通构造函数，创建自己的内存快
	{
		block = new MemBlock;
		strncpy(id, ID, size);
	}
	Counted(const Counted &other)	//拷贝构造函数
	{
		block = other.block;	//对内存快引用计数
		block->attach();
		strncpy(id, other.id, size);		//拷贝id，并加上后缀copy
		strncat(id, " copy", size - strlen(id));
	}
	void unalias() {block = block->unalias();}
	void addname(const char *nm)
	{
		strncat(id, nm, size - strlen(id));		//id上增加文字
	}
	Counted &operator=(const Counted &other)	//赋值函数
	{
		print("inside operator=\n\t");
		if(&other == this)		//检查自赋值
		{
			cout<<"self-assignment"<<endl;
			return *this;
		}
		//clean up what you are using first
		block->detach();
		block = other.block;
		block->attach();
		return *this;
	}
	//Decrement refcount, conditionally destroy
	~Counted()
	{
		cout<<"preparing to destroy:"<<id<<endl;
		cout<<"\tdecrementing refcount";
		block->print();
		cout<<endl;
		block->detach();
	}
	//Copy-on-write:
	void write(char value)
	{
		unalias();
		block->set(value);
	}
	void print(const char *msg = "")
	{
		if(*msg) cout<<msg<<" ";
		cout<<"object "<<id<<":";
		block->print();
		cout<<endl;
	}
private:
	class MemBlock
	{
	public:
		MemBlock()
		{
			memset(c, 1, size);
			refcount = 1;
			blocknum = blockcount++;
		}
		MemBlock(const MemBlock &mb)
		{
			memcpy(c, mb.c, size);
			refcount = 1;
			blocknum = blockcount++;
			print("copied block");
			cout<<endl;
			mb.print("from block");
		}
		~MemBlock()
		{
			cout<<"\tdestroying block"<<blocknum<<endl;
		}
		void print(const char *msg = "") const
		{
			if(*msg) cout<<msg<<", ";
			cout<<"blocknum:"<<blocknum<<", refcount:"<<refcount;
		}
		void attach()
		{
			++refcount;
		}
		void detach()
		{
			assert(refcount != 0);
			//Destroy object if no one use is using it
			if(--refcount == 0) delete this;
		}
		int count() const {return refcount;}
		void set(char x) {memset(c, x, size);}
		//conditionally copy this memblock
		//call before modifying the block;
		//assign resulting pointer to your block;
		MemBlock *unalias()
		{
			//Don't duplicate if not aliased:
			if(refcount == 1) return this;
			--refcount;
			//use copy constructor to duplicate
			return new MemBlock(*this);
		}
	private:
		static const int size = 100;
		char c[size];
		int refcount;
		static int blockcount;
		int blocknum;
	};
	
	MemBlock *block;
	static const int size = 30;
	char id[size];
};

int Counted::MemBlock::blockcount = 0;

int main()
{
	Counted A("A"), B("B");
	Counted C(A);
	C.addname(" (C) ");
	A.print();
	B.print();
	C.print();
	B = A;
	A.print("after assignment\n\t");
	B.print();
	cout<<"Assigning C = C"<<endl;
	C = C;
	C.print("calling C.write('x')\n\t");
	C.write('x');
	cout<<endl<<"exiting main()"<<endl;
}
