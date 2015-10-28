#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	clock_t start, finish;
	start = clock();

	for (size_t i = 0; i < 10000000000; i++);

	finish = clock();
	double totaltime = (double)(finish-start)/CLOCKS_PER_SEC;
	std::cout << totaltime*1000 << "ms" << std::endl;
	return 0;
}
