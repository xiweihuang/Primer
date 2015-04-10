#include <iostream>
#include <string>
#include <cctype>

using namespace std;


int main()
{
	// string s1;  // 默认初始化，为空字符串
	// string s2 = s1;
	// string s3 = "hiya";
	// string s4(10, 'c');

	// int size = s3.size();
	// cout << size << endl;

	// string s;
	// cin >> s;
	// cout << s << endl;

	// ===== 读取未知数量的string对象
	// string word;
	// while (cin >> word) {
	// 	cout << word << endl;
	// }

	// ===== 使用getline读取一整行
	// 触发getline函数返回的那个换行符实际上被丢弃掉了，得到的string对象中并不包含该换行符
	// string line;
	// while (getline(cin, line)) {
	// 	cout << line << endl;
	// }

	// ===== string的empty和size操作
	// string line;
	// while (getline(cin, line)) {
	// 	if (!line.empty()) {
	// 		cout << line << endl;
	// 	}
	// }


	// ===== string::size_type类型
	// string::size_type是一个无符号类型的值，可以存放下任何string对象的大小
	// 因其是无符号整型数，所以如果在表达式中混用了带符号数和无符号数将可能产生意想不到的结果
	// string line("jfkklsjlfkja;f");
	// // auto length = line.size();
	// string::size_type length = line.size();
	// cout << length << endl;

	// ===== 使用基于范围的for语句
	string s("Hello World!!!");
	// string::size_type punct_cnt = 0;
	decltype(s.size()) punct_cnt = 0;
	// for (auto c : s) {
	// 	if (ispunct(c))
	// 		punct_cnt++;
	// }

	// for (string::size_type i = 0; i < s.size(); i++) {
	// 	// if (ispunct(s[i])) {
	// 	// 	punct_cnt++;
	// 	// }
	// 	s[i] = toupper(s[i]);
	// }
	// // cout << punct_cnt << endl;
	// cout << s << endl;

	for (auto &c : s) {
		c = toupper(c);
	}
	cout << s << endl;

	return 0;
}






















