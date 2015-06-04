#include <iostream>
#include <list>
#include <deque>
#include <vector>
using namespace std;

typedef vector<int>::iterator iter;
// using iter = vector<int>::iterator;

iter findIntegerInVec(iter beg, iter end, int num) {
	while (beg != end) {
		if (num == *beg) {
			return beg;
		}
		beg++;
	}
	return end;
}

int main()
{
	// list<deque<int>> ld;
	vector<int> vi{10,20,120,30,100};
	// bool bIsFound = findIntegerInVec(vi.begin(), vi.end(), 100);
	iter bIter = findIntegerInVec(vi.begin(), vi.end(), 20);

	if (bIter != vi.end()) {
		cout << *bIter << endl;
	} else {
		cout << "can not found" << endl;
	}

	// cout << bIsFound << endl;

	return 0;
}