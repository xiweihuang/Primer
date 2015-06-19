#include <iostream>
#include <vector>

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

void fcn5() {
	int a = 20;
	auto f = [a] (int c) {
		// int sum = a + c;
		// return sum;
		if (a+c > 0)
			return 1;

		return 2;
	};
	cout << f(5) << endl;  // 25
}

void fcn6() {
	vector<int> vi = {0, 1, -1, 34, 2141, -12};
	auto f = [] (int i) -> int {
		if (i < 0) 
			return -i;
		else
			return i;
	};
	transform(vi.begin(), vi.end(), vi.begin(), f);

	for (const auto &val : vi) {
		cout << val << endl;
	}
}

// 指定lambda返回类型
// 如果lambda体包含return之外的任何语句，则编译器假定此lambda返回void

void exercise_10_20();
void exercise_10_21();

int main()
{
	// fcn3();
	// fcn4();
	// fcn5();
	// fcn6();

	// exercise_10_20();
	exercise_10_21();
	return 0;
}

void exercise_10_20() {
	vector<string> vs = {"Kobe", "Jordan", "James", "Wade", "Durcant"};
	vector<string>::size_type sz = 6;
	auto wc = count_if(vs.begin(), vs.end(), [sz](const string &s){ return s.size() >= sz; });
	cout << wc << endl;
}

// 10.21 编写一个lambda，捕获一个局部int变量，并递减变量值，直至它变为0.一旦变量变为0，再调用lambda应该不再递减变量。lambda应该返回一个bool值，指出捕获的变量是否为0
void exercise_10_21() {
	int cnt = 10;
	auto f = [&cnt] {
		bool bIsZero = cnt;
		while (cnt) {
			--cnt;
		}
		return (!bIsZero);
	};
	cout << f() << endl;
	cout << f() << endl;
}










