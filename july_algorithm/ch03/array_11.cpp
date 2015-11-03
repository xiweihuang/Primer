/**********

【最长回文子串】

**********/

#include <iostream>
#include <string>
using namespace std;

int CalLongPalindrome(const string& str)
{
	int mp = 1;
	for (int i = 0; i < str.size(); ++i) {
		int j = 1;
		while (i + j < str.size() && i - j >= 0 && str[i+j] == str[i-j])
			++j;
		mp = max(2*j-1, mp);

		j = 0;
		while (i - j >= 0 && i + 1 + j < str.size() && str[i-j] == str[i+1+j])
			++j;
		mp = max(2*j, mp);
	}
	return mp;
}

// void Manacher(string& str, int* p)
// {
// 	int size = str.size();
// 	p[0] = 1;
// 	int id = 0;
// 	int mx = 1;
// 	for (int i = 1; i < size; ++i) {
// 		if (mx > i) {
// 			p[i] = min(p[2*id-i], mx-i);
// 		} else {
// 			p[i] = 1;
// 		}

// 		for ( ; str[i+p[i]] == str[i-p[i]]; p[i]++);
// 	}
// }

int main()
{
	string str = "12312344321";
	cout << CalLongPalindrome(str) << endl;
	return 0;
}
