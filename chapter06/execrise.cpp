#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

bool is_empty1(const string &s)
{
	return s.empty();
}

bool has_big_char(const string &s)
{
	// for (auto c : s) {
	// 	if (c >= 'A' && c <= 'Z') {
	// 		return true;
	// 	}
	// }

	// for (auto beg = s.begin(); beg != s.end(); ++beg) {
	// 	if (*beg >= 'A' && *beg <= 'Z') {
	// 		return true;
	// 	}
	// }

	for (string::size_type i = 0; i != s.size(); ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			return true;
		}
	}
	return false;
}

void change_string_to_little(string &s)
{	
	for (auto &c : s) {
		c = tolower(c);
	}
}

// ===== ex6.18
// bool compare(matrix &a, matrix &b);
// vector<int> change_val(int, vector<int> &vi);

int count(const string &s, char c)
{
	return 1;
}
int sum(vector<int>::iterator it1, vector<int>::iterator it2, double n)
{
	return 1;
}

int main()
{
	// ===== ex6.16
	// string str = "hello";
	// cout << is_empty1(str) << endl;
	// cout << is_empty1("") << endl;

	// const string &str1 = str;
	// cout << is_empty1(str1) << endl;

	// ===== ex6.17
	// cout << has_big_char("dsa;0") << endl;
	// cout << change_string_to_little("fds;AAA") << endl;
	// string s = "fdsAGk";
	// change_string_to_little(s);
	// cout << s << endl;

	// ===== ex6.19
	count("abcde", 'a');
	vector<int> vec = {1,2,3};
	sum(vec.begin(), vec.end(), 3.8);





	return 0;
}