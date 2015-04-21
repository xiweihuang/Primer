// array.cpp

#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

string sa[10];
int ia[10];

int main()
{
	// unsigned buf_size = 1024;
	// int ia[buf_size];
	// for (auto s : sa) {
	// 	if (s.empty()) 
	// 		cout << "empty" << endl;
	// }

	// for (int i = 0; i < 10; i++)
	// 	cout << ia[i] << endl;

	// string sa2[10];
	// int ia2[10];

	// for (int i = 0; i < 10; i++)
	// 	cout << ia2[i] << "  ";
	// cout << endl;


	// int a[] = {10, 20, 30, 40, 50};
	// int *p = a;
	// for (int i = 0; i < 5; i++) {
	// 	*(p+i) = 0;
	// }
	// int a[10];
	// int *beg = begin(a);
	// int *e = end(a);

	// for (int *i = beg; i != e; i++) {
	// 	*i = 0;
	// }

	// for (auto i : a) {
	// 	cout << i << "   ";
	// }
	// cout << endl;

	// string s("Hello World!");
	// const char *str = s.c_str();
	// cout << str[1] << endl;

	// int int_arr[] = {0, 1, 2, 3, 4, 5};
	// vector<int> ivec(begin(int_arr), end(int_arr));

	// for (auto num : int_arr) {
	// 	cout << num << endl;
	// }

	vector<int> vi{1,2,3,4,5};
	int arr[5];

	for (int *pi = begin(arr); pi != end(arr); ++pi) {
		*pi = vi[pi-begin(arr)];
	}

	for (auto num : arr) {
		cout << num << "   ";
	}
	cout << endl;


	return 0;
}

