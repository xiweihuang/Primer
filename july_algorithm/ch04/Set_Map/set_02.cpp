#include <set>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

void test1()
{
	vector<pair<string, int>> ivec;
	for (size_t i = 0; i < 10; ++i) {
		// 3种创建pair的方法
		ivec.push_back({"Hello", 10});
		ivec.push_back(make_pair("Hello", 10));
		ivec.push_back(pair<string, int>("Hello", 10));
	}

	for (const auto& v : ivec) {
		cout << v.first << endl;
	}
}

void test2()
{
	set<int> set2;
	set2.insert(1);
	
}

int main()
{
	// vector<int> ivec;
	// for (size_t i = 0; i != 10; ++i) {
	// 	ivec.push_back(i);
	// 	ivec.push_back(i);
	// }

	// set<int> iset(ivec.cbegin(), ivec.cend());
	// multiset<int> miset(ivec.cbegin(), ivec.cend());
	// cout << ivec.size() << endl;
	// cout << iset.size() << endl;
	// cout << miset.size() << endl;

	// test1();
	test2();

	return 0;
}