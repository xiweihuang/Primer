#include <iostream>

using namespace std;

// void print(const int *beg, const int *end)
// {
// 	while (beg != end) {
// 		cout << *beg++ << endl;
// 	}
// }

void print(int (&arr)[10])
{
	for (auto elem : arr) {
		cout << elem << endl;
	}
}

int find_max(const int &num1, const int *p)
{
	return (num1 > *p ? num1 : *p);
}

void swap_point(int *&p1, int *&p2)
{
	int *p = p1;
	p1 = p2;
	p2 = p;
}

int main(int argc, char *argv[])
{
	// int j[10] = {0, 1};
	// // print(begin(j), end(j));
	// print(j);

	// int a = 10;
	// int b = 20;
	// int *p = &b;

	// cout << find_max(a, p) << endl;

	// int a = 10, b = 20;
	// int *p1 = &a, *p2 = &b;
	// swap_point(p1, p2);
	// cout << *p1 << *p2 << endl;

	for (size_t i = 1; i != argc; ++i) {
		cout << argv[i] << endl;
	}

	return 0;
}