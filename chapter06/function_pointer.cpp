
// #include <iostream>
// #include <string>

// using namespace std;

// bool lengthCompare(const string &s1, const string &s2) {
// 	return s1.size() >= s2.size();
// }

// typedef bool Func(const string &, const string &);
// typedef decltype(lengthCompare) Func2;

// typedef bool (*FuncP)(const string &, const string &);
// typedef decltype(lengthCompare) *FuncP2;

// // void useBigger(const string &s1, const string &s2, bool (*pf)(const string &, const string &)) {
// // 	cout << pf(s1, s2) << endl;
// // }

// void useBigger(const string &s1, const string &s2, Func func) {
// 	cout << func(s1, s2) << endl;
// }

// // void useBigger(const string &s1, const string &s2, bool pf(const string &, const string &)) {

// // }

// int main()
// {
// 	// bool (*pf)(const string &, const string &);
// 	// pf = lengthCompare;
// 	// cout << pf("abc", "abcd") << endl;
// 	string s1 = "hello______";
// 	string s2 = "welcome";
// 	useBigger(s1, s2, lengthCompare);
// 	return 0;
// }


#include <iostream>
#include <string>
using namespace std;

bool lengthCompare(const string &s1, const string &s2) {
	return s1.size() >= s2.size();
}

// -- method 1
// typedef bool (*Func)(const string &, const string &);
// void useBigger(const string &s1, const string &s2, Func func) {
// 	cout << (*func)(s1, s2) << endl;
// } 

// -- method 2
// typedef bool Func(const string &, const string &);
// void useBigger(const string &s1, const string &s2, Func func) {
// 	cout << func(s1, s2) << endl;
// }

// -- method 3
// typedef decltype(lengthCompare) Func;
// void useBigger(const string &s1, const string &s2, Func func) {
// 	cout << func(s1, s2) << endl;
// }

// -- method 4
typedef decltype(lengthCompare) *Func;
void useBigger(const string &s1, const string &s2, Func func) {
	cout << (*func)(s1, s2) << endl;
}

int main() 
{
	string s1 = "12345111111111";
	string s2 = "1111111";
	useBigger(s1, s2, lengthCompare);
	return 0;
}

