#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1, s2;
	do{
		cin >> s1;
		cin >> s2;
		cout << ((s1 > s2) ? s1 : s2) << endl;
	} while (cin);
	return 0;
}