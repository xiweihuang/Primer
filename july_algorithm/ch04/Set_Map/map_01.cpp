#include <map>
#include <string>
#include <iostream>
using namespace std;

void test1()
{
	// map<string, size_t> word_count;
	// string word;
	// while (cin >> word)
	// 	++word_count[word];
	// for (const auto& w : word_count) {
	// 	cout << w.first << " occurs " << w.second << (w.second > 1 ? "times" : "time") << endl;
	// }
}

// insert 的4种插入方式
void test2()
{
	map<string, int> mp;
	// mp.insert({"Kobe", 35});
	mp.insert(make_pair("Jordan", 45));
	mp.insert(pair<string, int>("James", 30));
	mp.insert(map<string, size_t>::value_type("Durant", 25));

	mp["Wade"] = 33;
	for (map<string, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter) {
		cout << iter->first << ", " << iter->second << endl;
	}
}

void test3()
{
	multimap<string, int> mp;
	mp.insert({"Kobe", 35});
	mp.insert({"Jordan", 40});
	mp.insert({"James", 30});
	mp.insert({"Jordan", 45});

	for (auto beg = mp.lower_bound("Jordan"), end = mp.upper_bound("Jordan"); beg != end; ++beg) {
		cout << beg->first << ", " << beg->second << endl;
	}

	for (auto pos = mp.equal_range("Jordan"); pos.first != pos.second; ++pos.first) {
		
	}
}

int main()
{
	// test1();
	// test2();
	test3();
	return 0;
}