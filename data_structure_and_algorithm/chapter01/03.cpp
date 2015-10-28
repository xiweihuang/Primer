
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
const T& findMax(const vector<T>& vec)
{
	// T max = vec[0];
	int maxIndex = 0;
	for (size_t i = 1; i < vec.size(); ++i) {
		if (vec[i] > vec[maxIndex]) {
			maxIndex = i;
		}
	}
	return vec[maxIndex];
}

int main()
{
	// vector<int> vec = {1, 2, 3, 2, 1};
	vector<char> vec = {'a', 'b', 'c', 'a', 'b'};
	cout << findMax(vec) << endl;
	return 0;
}
