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

using namespace std;

// 扩展程序，忽略大小写和标点。
// 例如"example.","example,"和"Example"应该递增相同的计数器
void useMap() {
	map<string, size_t> word_count;
	string word;
	while (cin >> word) {
		string 
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

int main()
{
	// useMap();
	useSet();
	return 0;
}
