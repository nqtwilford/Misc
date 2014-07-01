#include <iostream>
using namespace std;

//最大公约数
int GetGCD(int n, int m)
{
    if (m < n)
    {
        m ^= n;
        n ^= m;
        m ^= n;
    }

    if (n == 0)
        return m;
    else
        return GetGCD(n, m % n);
}
//最小公倍数
int GetLCM(int n, int m)
{
	return n * m / GetGCD(n, m);
}

int main()
{
	cout<<GetGCD(4453, 5767)<<endl;
	cout<<GetLCM(4453, 5767)<<endl;
	return 0;
}
