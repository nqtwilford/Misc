#include <iostream>
using namespace std;

class Test
{
public:
Test( void )
{
std::cout << "Test constructed in default mode" << std::endl;
}
Test( int t )
{
std::cout << "Test constructed with arguments" << std::endl;
}
~Test( void )
{
std::cout << "Test destructed" << std::endl;
}
};
int main( int argc,char *argv[] )
{
Test *aa_ = new Test( 10 );
delete aa_;
Test *bb_ = (Test *)malloc( sizeof(Test) );
free( bb_ );
Test *cc_ = (Test *)malloc( sizeof(Test) );
new (cc_) Test( );	//�˴�ָ�����ڴ�λ��cc_�ϣ�ִ�й��캯����ʵ�ʲ�δ����ռ�
free( cc_ );
return 0;
}
