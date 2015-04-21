#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	// ===== 定义和初始化vector对象
	// vector<int> ivec;
	// vector<int> ivec2(ivec);
	// vector<int> ivec3 = ivec;

	// 列表初始化
	// vector<string> vec = { "a", "an", "fd" };
	// vector<string> vec{"Kobe", "Jordan", "James"};
	// for (auto &s : vec) {
	// 	cout << s << endl;
	// }

	// 创建指定数量的元素
	// vector<int> vec(10, 1);

	// 值初始化


	// =====
	// vector<unsigned> scores(11, 0);
	// unsigned grade;
	// while (cin >> grade) {
	// 	if (grade <= 100)
	// 		++scores[grade/10];
	// }

	// ===== ex3.17
	vector<string> vs;
	string s;
	while (cin >> s) {
		vs.push_back(s);
	}

	for (auto &s : vs) {
		for (auto &c : s) {
			c = toupper(c);
		}
	}

	// for (auto s : vs) {
	// 	cout << s << endl;
	// }
	// vector<string>::size_type
	for (decltype(vs.size()) i = 0; i != vs.size(); i++) {
		cout << vs[i] << endl;
	}


	return 0;
}