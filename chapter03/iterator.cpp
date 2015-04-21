#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int main()
{
	// string s("some string");
	// if (s.begin() != s.end()) {
	// 	auto it = s.begin();
	// 	*it = toupper(*it);
	// }
	// cout << s << endl;

	// ===== const_iterator
	// vector<int> vi = {10,20,30};
	// for (auto it = vi.cbegin(); it != vi.cend(); ++it) {
	// 	// *it = 0; // cbegin和cend返回的是const_iterator
	// }

	// ===== ex3.23
	// vector<int> vi;
	// for (int i = 0; i < 10; i++) {
	// 	vi.push_back(i);
	// }

	// for (auto it = vi.begin(); it != vi.end(); it++) {
	// 	(*it) *= (*it);
	// }

	// for (auto num : vi) {
	// 	cout << num << "   ";
	// }
	// cout << endl;


	// =====
	// vector<int> vi = {10, 20, 30};
	// auto it = vi.begin();
	// it += 4;
	// if (it != vi.end()) {
	// 	cout << "fds" << endl;
	// 	cout << *it << endl;
	// }

	// if (it == vi.end())
	// 	cout << "true" << endl;

	// vector<int> v1(10, 42);
	// vector<int> v2 = { 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
	// vector<int> v3;
	// for (int i = 0; i < 10; i++) {
	// 	v3.push_back(42);
	// }

	// vector<int> vi = {100, 200, 300, 400, 500};
	// for (decltype(vi.size()) i = 0; i < vi.size() - 1; i++) {
	// 	int sum = vi[i] + vi[i+1];
	// 	cout << sum << "   ";
	// }

	// for (auto it = vi.begin(); it != vi.end() - 1; it++) {
	// 	int sum = *it + *(it+1);
	// 	cout << sum << "   ";
	// }

	// for (auto beg = vi.begin(), end = vi.end() - 1; beg <= end; beg++, end--) {
	// 	int sum = *beg + *end;
	// 	cout << sum << "   ";
	// }

	// for (decltype(vi.size()) i = 0; i <= vi.size()/2; i++) {
	// 	int sum = vi[i] + vi[vi.size() - i - 1];
	// 	cout << sum << "   ";
	// }
	// cout << endl;


	// ===== 二分搜索
	vector<int> text = {10, 20, 30, 40, 50};
	auto beg = text.begin(), end = text.end();
	auto mid = beg + (end - beg)/2;

	int sought = 40;

	while (mid != end && *mid != sought) {
		if (sought < *mid)
			end = mid;
		else
			beg = mid + 1;
		mid = beg + (end - beg)/2;
	}

	return 0;
}




















