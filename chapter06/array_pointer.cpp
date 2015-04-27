#include <iostream>
#include <string>
// #include <iterator>

using namespace std;

// typedef int (*arrT)[5];

// int odd[] = {1,3,5,7,9};

string str[2] = {"hello", "world"};

// arrT func() {
// 	return &odd;
// }

// int (*fun()) [5] {
// 	return &odd;
// }

// auto func(int i) -> int (*) [5] {
// 	return &odd;
// }

// decltype(odd) *func(int i) {
// 	return &odd;
// }

// ================
typedef string (&arrT)[2];
string (&func1()) [2] {
	return str;
}


// arrT func1() {
// 	return str;
// }

// auto func1() -> string (&) [2] {
// 	return str;
// }

// decltype(str) &func1() {
// 	return str;
// }




int main()
{
	// typedef int arrT[10];

	// arrT b = {1,2,3,4,5,6,7,8,9,10};
	// for (size_t i = 0; i < 10; i++) {
	// 	cout << b[i] << endl;
	// }

	// typedef double mydouble;
	// mydouble dd = 1.23456;
	// cout << dd << endl;

	// int arr[5] = {1,2,3,4,5};

	arrT p = func1();
	// int p[5] = {1,2,3,4,5};

	// cout << *p << endl;

	for (auto beg = begin(p); beg != end(p); ++beg) {
		cout << *beg << endl;
	}

	// for (size_t i = 0; i < 2; ++i) {
	// 	cout << *(p+i) << endl;
	// }

	return 0;
}
