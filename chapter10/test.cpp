#include <stdio.h>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	vector<int> vi;
	auto it = back_inserter(vi);
	for (size_t idx = 0; idx != 10; ++idx) {
		*it = idx;
		// ++it;
	}

	for (auto &val : vi)
		printf("%d\n", val);
	return 0;
}