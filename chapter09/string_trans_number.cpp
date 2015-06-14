// string的数值转换

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void basic() {
	int i = 42;
	string s = to_string(i);
	printf("%s\n", s.c_str());
	double d = stod(s);
	printf("%lf\n", d);

	string s2 = "pi = 3.14";
	auto dd = stod(s2.substr(s2.find_first_of("+-.0123456789")));
	printf("%lf\n", dd);
}

void exercise1();
void exercise1_1();

int main()
{
	// basic();
	exercise1();
	exercise1_1();
	return 0;
}

// 1. 编写程序处理一个vector<string>，其元素都表示整型值。计算vector中所有元素之和。修改程序，使之计算表示浮点值的string之和。
void exercise1() {
	vector<string> vs = {"123.1", "312", "34567"};
	int sum = 0;
	for (auto &val : vs) {
		auto num = stoi(val);
		sum += num;
	}
	printf("%d\n", sum);
}

void exercise1_1() {
	vector<string> vs = {"123.1", "234.2", "123124"};
	double sum = 0;
	for (auto &val : vs) {
		auto num = stod(val);
		sum += num;
	}
	printf("%lf\n", sum);
}

// 2. 设计一个类，它有三个unsigned成员，分别表示年、月和日。为其编写构造函数，接受一个表示日期的string参数。你的构造函数应该能处理不同数据格式，如January 1, 1900、 1/1/1990、Jan 1 1900等。
class Date {
public:
	Date(string s) {
		// if ( auto pos = s.find_first_not_of(numbers_))
		// auto pos_char = s.find_first_not_of(numbers_)
		// if (pos_char != string.npos) {

		// }
	}
private:
	string numbers_ = "0123456789";
	unsigned year_, month_, day_;
};



