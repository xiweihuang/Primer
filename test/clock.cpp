#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <time.h>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_map<int, int> mp;  // mp用来保存，vector中每个数字，所对应的和为target的数字
		vector<int> result;

		int idx = 1;
		for (auto &num : numbers) {
			if (mp.find(num) == mp.end()) {
				mp[target - num] = idx;
			} else {
				result.push_back(mp[num]);
				result.push_back(idx);
				break;
			}
			++idx;
		}
		return result;
	}

};

int main()
{
	auto start_time = clock();
	vector<int> numbers = {3, 2, 4};
	Solution s;
	auto ret = s.twoSum(numbers, 6);
	// for (const auto &val : ret) {
	// 	printf("%d\n", val);
	// }
	auto end_time = clock();
	cout << end_time - start_time << endl;
	return 0;
}
