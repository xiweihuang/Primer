#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	vector<int> vi = {1,2,3,4};
	// auto pi = vi.begin();
	// cout << *pi << endl;
	auto n = *(vi.begin());
	cout << n << endl;

	return 0;
}