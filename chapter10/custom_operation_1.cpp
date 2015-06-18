// 定制操作
// 向算法传递函数
// 谓词

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

void test() {
	vector<string> vs = {"Wade", "Kobe", "Joe", "Jordan"};
	// sort(vs.begin(), vs.end(), isShorter);
	sort(vs.begin(), vs.end());  // "Joe", "Jordan", "Kobe", "Wade"

	// stable_sort():
	stable_sort(vs.begin(), vs.end(), isShorter);  // "Joe", "Kobe", "Wade", "Jordan"

	for (auto iter = vs.cbegin(); iter != vs.cend(); ++iter) {
		printf("%s\n", (*iter).c_str());
	}
}

class Sales_data {
public:
	Sales_data(const string &iisbn) : isbn_(iisbn) {}
	string isbn() const {
		return isbn_;
	}
private:
	string isbn_;
};

bool compareIsbn(const Sales_data &s1, const Sales_data &s2) {
	return s1.isbn() < s2.isbn();
}

void exercise_10_12() {
	vector<Sales_data> vs;
	vs.emplace_back("c123456");
	vs.emplace_back("a25235");
	vs.emplace_back("b1221312");

	sort(vs.begin(), vs.end(), compareIsbn);

	for (const auto &val : vs) {
		printf("%s\n", val.isbn().c_str());
	}
}

bool string_size_bigger_than_five(const string &str) {
	return (str.size() >= 5);
}

void exercise_10_13() {
	vector<string> vs = {"Kobe", "Jordan", "James", "Wade", "Durcant"};
	auto iter_partition = partition(vs.begin(), vs.end(), string_size_bigger_than_five);

	for (auto iter = vs.begin(); iter != iter_partition; ++iter) {
		printf("%s\n", (*iter).c_str());
	}

}

int main()
{
	// test();
	// exercise_10_12();
	exercise_10_13();
	return 0;
}
