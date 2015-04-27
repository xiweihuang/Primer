#include <iostream>
#include <string>

using namespace std;

void print_str(string &str) {
	cout << "1:  " << str << endl;
}

void print_str(const string &str) {
	cout << "2:  " << str << endl;
}

int main()
{
	// const char *p = "Hello World"; // "Hello World"，一个数组，首字符的地址。
	// // const char *p = &a;
	// cout << p << endl;
	// // char *p = "Hello";
	// // cout << p << endl;

	string s = "hello";
	print_str(s);

	print_str("hello world!");

	return 0;
}
