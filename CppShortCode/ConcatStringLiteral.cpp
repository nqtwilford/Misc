//如果连接char字符串和wchar_t字符串会出现怪异的现象
#include <iostream>
int main()
{
	std::cout << "a multi-line "
						"string literal "
						L"using concatenation"
						<< std::endl;
}
