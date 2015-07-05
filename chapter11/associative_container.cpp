// 关联容器
// 标准库有8个关联容器
// 三个维度作区分：
// 1. map/set
// 2. 重复/不重复 关键字      -- 允许重复的都加multi
// 3. 顺序/无序

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <list>

using namespace std;

// 扩展程序，忽略大小写和标点。
// 例如"example.","example,"和"Example"应该递增相同的计数器
void useMap() {
	map<string, size_t> word_count;
	string word;
	while (cin >> word) {
		++word_count[word];
	}
	for (const auto &w : word_count) {
		cout << w.first << ",  " << w.second << endl;
	}
}

void useSet() {
	map<string, size_t> word_count;
	set<string> exclude = {"Jordan", "Duncan"};
	string word;
	while (cin >> word) {
		if (exclude.find(word) == exclude.end()) {
			++word_count[word];
		}
	}
	for (const auto &w : word_count) {
		cout << w.first << ",  " << w.second << endl;
	}        
}

void init() {
	map<string, size_t> word_count;
	set<string> exclude = {"Kobe", "Jordan"};
	map<string, int> authors = { {"Kobe", 35}, {"Jordan", 45} };
	for (const auto &player : authors) {
		cout << player.first << ",  " << player.second << endl;
	}
}

void multi() {
	vector<int> ivec;
	for (int i = 0; i != 10; ++i) {
		ivec.push_back(i);
		ivec.push_back(i);
	}

	set<int> iset(ivec.begin(), ivec.end());
	multiset<int> miset(ivec.cbegin(), ivec.cend());

	cout << ivec.size() << endl;
	cout << iset.size() << endl;
	cout << miset.size() << endl;

}

// void add_family(map<string, vector<string>> &family, )

void exercise_11_05() {
	map<string, vector<string>> family;
	family["Michael"] = {"Jordan", "Jackson"};

	for (const auto &val : family) {
		for (const auto &vv : val.second) {
			cout << val.first << " " << vv << endl;
		}
	}
}

void exercise_11_08() {
	vector<string> vs;
	string word;
	while (cin >> word) {
		if (find(vs.begin(), vs.end(), word) == vs.end()) {
			vs.push_back(word);
		}
	}
	for (const auto &val : vs) {
		cout << val << endl;
	}
}

void exercise_11_08_set() {
	set<string> ss;
	string word;
	while (cin >> word) {
		if (ss.find(word) == ss.end()) {
			ss.insert(word);
		}
	}
	cout << "============" << endl;
	for (const auto &val : ss) {
		cout << val << endl;
	}
}

void exercise_11_09() {
	map<string, list<int>> word_line;
}

void exercise_11_10() {
	map<vector<int>::iterator, int> m1;
	map<list<int>::iterator, int> m2;
}

class Sales_data {
public:
	Sales_data(const string &isbn) : _isbn(isbn) {}
	string isbn() const {
		return _isbn;
	}
private:
	string _isbn;
};

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
	return lhs.isbn() < rhs.isbn();
}

void exercise_11_11() {
	// multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
	typedef bool(*func)(const Sales_data &, const Sales_data&);
	multiset<Sales_data, func> bookstore(func);
}

int main()
{
	// useMap();
	// useSet();
	// init();
	// multi();
	// exercise_11_05();
	// exercise_11_08();
	// exercise_11_08_set();
	// exercise_11_09();
	// exercise_11_10();
	exercise_11_11();
	return 0;
}
