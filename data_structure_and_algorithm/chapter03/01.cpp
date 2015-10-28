#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
	Vector<int> vec;
	for (int i = 0; i < 20; ++i) {
		vec.push_back(i);
	}

	for (auto ptr = vec.begin(); ptr != vec.end(); ++ptr) {
		cout << *ptr << "  ";
	}
	cout << endl;
	return 0;
}