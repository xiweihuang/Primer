#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>

using namespace std;

void iterator_map() {
	map<string, int> mp = {
		{"Kobe", 45},
		{"Jordan", 50}
	};
	auto mp_it = mp.begin();
	cout << mp_it->first << mp_it->second << endl;
}

void iterator_set() {
	set<int> st = {10, 20, 30, 5};
	auto st_it = st.begin();
	cout << *st_it << endl;
}

void inserter_map() {
	map<string, size_t> word_count;
	string word;
	while (cin >> word) {
		auto ret = word_count.insert(make_pair(word, 1));
		if (!ret.second) {
			// ++ret.first->second;
			++(ret.first->second);
		}
	}

	for (const auto &val : word_count) {
		cout << val.first << ", " << val.second << endl;
	}
}

void visit() {
	set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto iter = iset.lower_bound(5);
	cout << *iter << endl;
}

void find1() {
	multimap<string, int> mp = {
		{"Kobe", 10},
		{"Jordan", 20},
		{"Jordan", 30},
		{"Kobe", 40},
		{"James", 50}
	};
	auto cnt = mp.count("Kobe");
	auto iter = mp.find("Kobe");
	while (cnt) {
		cout << iter->first << ", " << iter->second << endl;
		++iter;
		--cnt;
	}
}

void find2() {
	multimap<string, int> mp = {
		{"Kobe", 10},
		{"Jordan", 20},
		{"Jordan", 30},
		{"Kobe", 40},
		{"James", 50}
	};
	auto beg = mp.lower_bound("Kobe");
	auto end = mp.upper_bound("Kobe");
	for (; beg != end; ++beg) {
		cout << beg->first << ", " << beg->second << endl;
	}
}

void find3() {
	multimap<string, int> mp = {
		{"Kobe", 10},
		{"Jordan", 20},
		{"Jordan", 30},
		{"Kobe", 40},
		{"James", 50}
	};
	auto range = mp.equal_range("Jordan");
	for (auto iter = range.first; iter != range.second; ++iter) {
		cout << iter->first << ", " << iter->second << endl;
	}
}

void exercise_11_28() {
	map<string, vector<int>> mp;
	mp["Kobe"] = {81, 62, 55};
	map<string, vector<int>>::iterator it = mp.find("Kobe");
	for (const auto &val : (it->second)) {
		cout << val << endl;
	}
}

void exercise_11_29() {
	set<int> st = {1, 2, 3, 4, 5, 7, 8, 9};
	auto it1 = st.lower_bound(6);
	cout << *it1 << endl;  // 7 ? !

	auto it2 = st.upper_bound(6);
	cout << *it2 << endl;

	auto pair3 = st.equal_range(6);
	cout << *(pair3.first) << *(pair3.second) << endl;

}

void exercise_11_30() {
	multimap<string, int> mp = {
		{"Kobe", 10},
		{"Jordan", 20},
		{"Jordan", 30},
		{"Kobe", 40},
		{"James", 50}
	};

	// if (mp.find("James") != mp.end()) {
	// 	mp.erase("James");
	// }
	auto range = mp.equal_range("Kobe1");
	if (range.first != range.second) {
		// mp.erase(range.first, range.second);
		mp.erase("Kobe1");
	}
	for (const auto &val : mp) {
		cout << val.first << ", " << val.second << endl;
	}
}

int main()
{
	// iterator_map();
	// iterator_set();
	// inserter_map();
	// visit();

	// find1();
	// find2();
	// find3();

	// exercise_11_28();
	// exercise_11_29();
	exercise_11_30();
	return 0;
}
