// 默认初始化和值初始化

#include <iostream>
using namespace std;

// int a1[6];

// void print(int *p, int len) {
// 	for (size_t i = 0; i != len; ++i) {
// 		cout << *(p+i) << ", ";
// 	}
// 	cout << endl;
// }

// int main()
// {
// 	int a2[5];

// 	print(a1, 6);  // 0, 0, 0, 0, 0, 0
// 	print(a2, 5);  // 0, 0, 0, 0, 1439370272
// 	return 0;
// }

class Person {
public:
	int a[10];  // 没有类内初始值，执行默认初始化。
};

int main()
{
	Person p;
	for (int i = 0; i < 10; ++i) {
		cout << p.a[i] << ", ";  // 1591000128, 32767, 0, 0, 0, 0, 0, 0, 0, 0
	}
	cout << endl;
	return 0;
}