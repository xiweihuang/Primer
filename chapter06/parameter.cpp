#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#define NDEBUG

typedef string::size_type sz;
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ') {
	cout << ht << ' ' << wid << endl;
	return "hello";
}

int ff(int a, int b = 0, int c = 0) {

	return 1;
}

inline const string &shorterString(const string &s1, const string &s2) {
	return (s1.size() <= s2.size() ? s1 : s2);
}

constexpr int new_sz() {
	return 42;
}

void print(const int ia[], size_t size) {
	#ifndef NDEBUG
		cerr << __func__ << ": array size is " << size << endl;
	#endif
}

int main() 
{
	// screen();
	// const string &s = shorterString("hello", "world");
	// cout << s << endl;
	// auto a = new_sz();
	// cout << a << endl;

	// assert(0);
	int a[5] = {};
	print(a, 5);
	return 0;
}