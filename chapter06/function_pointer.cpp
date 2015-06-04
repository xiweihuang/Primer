//#include <iostream>
//#include <string>
//
//using namespace std;
//
//bool lengthCompare(const string &s1, const string &s2) {
//	return s1.size() >= s2.size();
//}
//
//typedef bool Func(const string &, const string &);
//typedef decltype(lengthCompare) Func2;
//
//typedef bool (*FuncP)(const string &, const string &);
//typedef decltype(lengthCompare) *FuncP2;
//
//// void useBigger(const string &s1, const string &s2, bool (*pf)(const string &, const string &)) {
//// 	cout << pf(s1, s2) << endl;
//// }
//
//void useBigger(const string &s1, const string &s2, Func func) {
//	cout << func(s1, s2) << endl;
//}
//
//// void useBigger(const string &s1, const string &s2, bool pf(const string &, const string &)) {
//
//// }
//
//int main()
//{
//	// bool (*pf)(const string &, const string &);
//	// pf = lengthCompare;
//	// cout << pf("abc", "abcd") << endl;
//	string s1 = "hello______";
//	string s2 = "welcome";
//	useBigger(s1, s2, lengthCompare);
//	return 0;
//}

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s = "Hello";
	cout << s << endl;
	return 0;
}

