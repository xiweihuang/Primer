#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0;
	while (cin >> a >> b) {
		try {
			if (b == 0) {
				throw runtime_error("b can't be zero");
			}
			cout << (a/b) << endl;
		} catch (runtime_error err) {
			cout << "haha" << err.what() << endl;
			cout << "try again?(y/n):";
			char ch;
			cin >> ch;
			if (ch == 'n')
				break;
		}
	}
	cout << "good" << endl;
	return 0;
}

