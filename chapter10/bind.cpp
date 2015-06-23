#include <vector>
#include <string>
#include <functional>
#include <iostream>

using namespace std;
using namespace std::placeholders;

void print(const string &s) {
	printf("%s\n", s.c_str());
}

bool check_size(const string &s, string::size_type sz) {
	return s.size() >= sz;
}

bool check_size_2(string::size_type sz, const string &s) {
	return s.size() >= sz;
}

void test() {
	vector<string> vs = {"Kobe", "Jordan", "James"};
	// for_each(vs.begin(), vs.end(), [](const string &s){ printf("%s\n", s.c_str()); });
	// for_each(vs.begin(), vs.end(), print);

	string::size_type sz = 5;
	auto ptr = find_if(vs.begin(), vs.end(), [sz](const string &s){ return s.size() >= sz; });
	if (ptr != vs.end())
		printf("%s\n", (*ptr).c_str());
	else
		printf("can't find...");

	// find_if(vs.begin(), vs.end(), check_size);

}

void bind_test() {
	vector<string> vs = {"Kobe", "Jordan", "James"};

	// auto check6 = bind(check_size, _1, 6);
	auto check6 = bind(check_size_2, 6, _1);  // _1 是 check6 的第一个参数，传递给 check_size_2
	auto ptr = find_if(vs.begin(), vs.end(), check6);
	if (ptr != vs.end())
		printf("%s\n", (*ptr).c_str());
}

void bind_placeholders() {
	// auto g = bind(f, a, b, _2, c, _1);
	// 那么调用 g(_1, _2) 等同于 f(a, b, _2, c, _1)
}

ostream &print_ref(ostream &os, const string &s, char c) {
	return os << s << c;
}

// 绑定引用参数
void bind_ref() {
	vector<string> vs = {"Kobe", "Jordan", "James"};
	auto &os = cout;
	char c = '\n';
	for_each(vs.begin(), vs.end(), [&os, c](const string &s){ os << s << c; });

	for_each(vs.begin(), vs.end(), bind(print_ref, ref(os), _1, c));
}

void exercise_10_22();
void exercise_10_24();

int main()
{
	// test();
	// bind_test();
	// bind_ref();
	// exercise_10_22();
	exercise_10_24();
	return 0;
}


// 10.22 重写统计长度小于等于6的单词数量的程序，使用函数代替lambda
bool compare_word(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}
bool find_size(string::size_type sz, const string &s) {
	return s.size() > sz;
}
void exercise_10_22() {
	vector<string> words = {"Kobe", "Jordan", "James", "Durcant", "Durant"};
	sort(words.begin(), words.end(), compare_word);
	auto ptr = find_if(words.begin(), words.end(), bind(find_size, 5, _1));
	auto count = ptr - words.begin();
	cout << count << endl;
}
// 10.23 bind接受几个参数
// 10.24 给定一个string，使用bind和check_size在一个int的vector中查找第一个大于string长度的值
bool check_size_10_24(int num, string::size_type sz) {
	return num >= sz;
}
void exercise_10_24() {
	vector<int> vi = {1, 5, 2, 3, 3, 3};
	const string str = "Kobe";
	auto ptr = find_if(vi.begin(), vi.end(), bind(check_size_10_24, _1, str.size()));
	if (ptr != vi.end())
		printf("%d\n", *ptr);
}

// 10.25 在10.3.2节的练习中，编写了一个使用partition的biggies版本。使用check_size和bind重写此函数











