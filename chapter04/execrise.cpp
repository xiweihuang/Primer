#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// ===== ex4.12
	vector<int> vi = { 1, 2, 12, 4, 9, 15, 20 };
	for (auto &num : vi) {
		num = (num%2 != 0) ? num*2 : num;
	}

	for (auto beg = vi.begin(); beg != vi.end(); ++beg) {
		cout << *beg << "  ";
	}
	cout << endl;
	return 0;
}

