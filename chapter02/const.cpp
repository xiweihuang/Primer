#include <iostream>
using namespace std;

int main()
{
	// const int bufSize = 512;
	// bufSize = 1024;
	// cout << bufSize << endl;
	// const int bufSize;

	// 对常量的引用
	// const int ci = 1024;
	// const int &r1 = ci;

	// r1 = 42;
	// int &r2 = ci;

	// int i = 42;
	// const int &r1 = i; // true
	// const int &r2 = 42; // true
	// const int &r3 = r1*2; // true
	// int &r4 = r1*2; // false

	// int i = 42;
	// int &r1 = i;
	// const int &r2 = i; //常量引用仅对引用可参与的操作做出了限定，对于引用的对象本身是不是一个常量未做限定。

	// r1 = 50;
	// cout << r2 << endl;

	// ======================
	// const double pi = 3.14;
	// const double *ptr = &pi;

	// // *ptr = 3.1415
	// double dval = 12.123;
	// ptr = &dval;

	// const int *p;

	return 0;
}