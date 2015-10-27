#include <iostream>
using namespace std;

int sum(int n)
{
	int psum = 0;
	for (int i = 1; i < n; ++i) {
		psum += i*i*i;
	}
	return psum;
}