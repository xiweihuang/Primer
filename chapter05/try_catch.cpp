#include <iostream>

using namespace std;

int main()
{
	int a = 10;
	try{
		if (a == 10) {
			throw runtime_error("a is equal ten");
		}
	} catch (runtime_error err) {
		cout << err.what() << endl;
	}
	return 0;
}