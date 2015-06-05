#include <stdio.h>
#include <vector>
#include <list>

using namespace std;

bool compareVector(const vector<int> &v1, const vector<int> &v2) {
	// 先判断大小是否一样
	auto s1 = v1.size();
	auto s2 = v2.size();
	if (s1 != s2) {
		return false;
	} else {
		for (auto b1 = v1.begin(), b2 = v2.begin(); b1 != v1.end(); ++b1, ++b2) {
			if (*b1 != *b2)
				return false;
		}
	}
	return true;
}

bool compare_list_vector(const list<int> li, const vector<int> vi) {
	// for ((auto b1 = li.begin(); auto b2 = vi.begin()); b1 != li.end() || b2 != vi.end(); ++b1, ++b2) {
	// 	if (*b1 == *b2)
	// 		return true;
	// }
	if (li.size() != vi.size())
		return false;

	// 这里遇到一个问题，就是for循环的第一个表达式有多个类型不同的变量，该怎么办？
	// 可以把这些变量在for循环之前提取出来定义

	auto b1 = li.cbegin();
	auto b2 = vi.cbegin();
	auto e1 = li.cend();
	// auto e2 = vi.cend();

	for (; b1 != e1 ; ++b1, ++b2) {
		if (*b1 != *b2)
			return false;
	}
	return true;
}

int main()
{
	// vector<int> v1 = {1, 2, 3};
	// vector<int> v2 = {1, 2};
	// printf("%d\n", compareVector(v1, v2));

	list<int> li = {1, 2, 3};
	vector<int> vi = {1, 2, 3};
	printf("%d\n", compare_list_vector(li, vi));
	return 0;
}