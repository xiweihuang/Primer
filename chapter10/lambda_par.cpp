#include <iostream>

using namespace std;

// 可变lambda，其实就只对值捕获而言
void fcn3() {
	int v1 = 42;
	auto f = [v1] () mutable { return ++v1; };
	v1 = 0;
	cout << f() << endl;
}

void fcn4() {
	const int v1 = 42;
	// int v1 = 42;
	auto f = [&v1] () mutable { 
		// return ++v1; 
		return v1;
	};
	// v1 = 0;
	cout << f() << endl;
}

// 指定lambda返回类型
// 如果lambda体包含return之外的任何语句，则编译器假定此lambda返回void

int main()
{
	// fcn3();
	fcn4();
	return 0;
}