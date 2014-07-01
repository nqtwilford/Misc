#include <stdlib.h>
#include <iostream>
#include <time.h>

int rangeRand( int min, int max )
{
	return int((double)rand() / RAND_MAX * (max - min + 1) + min);
}
float rangeRand( float min, float max )
{
	return (float)rand() / RAND_MAX * (max - min) + min;
}

int main()
{
	srand( (unsigned)time( NULL ) );
	for (int i = 0; i < 10; ++i)
	{
		std::cout<<rangeRand(1, 10)<<std::endl;
	}
	
}
