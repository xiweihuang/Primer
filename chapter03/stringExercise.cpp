#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	// string s = "Hello World!!!";
	// for (char &c : s) {
	// 	c = 'X';
	// }

	// cout << s << endl;


	// string s;
	// cout << s[1] << endl;


	string s;
	cin >> s;
	for (auto &c : s) {
		if (!ispunct(c))
			cout << c;
	}
	cout << endl;
	return 0;
}