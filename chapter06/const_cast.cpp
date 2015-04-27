#include <iostream>
#include <string>

using namespace std;

const string &shorterString(const string &s1, const string &s2) {
	return (s1.size() < s2.size() ? s1 : s2);
}

string &shorterString(string &s1, string &s2) {
	auto &r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
	return const_cast<string &>(r);
}

// int calc(int a, int b) {
// 	cout << "1..." << endl;
// }
// int calc(const int a, const int b) {
// 	cout << "2..." << endl;
// }

// int get() {

// }
// double get() {

// }

int reset(int *p) {
	return 1;
}
double reset(double *p) {
	return 1.0;
}

int main() {
	string s1 = "hello ,";
	string s2 = "world";
	string &s = shorterString(s1, s2);

	s[3] = 'f';

	// cout << s << endl;
	cout << s2 << endl;

	return 0;
}
