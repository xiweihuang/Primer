// 委托构造函数
// 一个委托构造函数使用它所属类的（其他构造函数）执行它自己的初始化过程

// #include <string>

// class Sales_data {
// public:
// 	Sales_data(std::string s, unsigned cnt, double price) : bookNo(s), units_sold(cnt), revenue(cnt*price) {}

// 	// 委托构造
// 	Sales_data() : Sales_data("", 0, 0) {}
// 	Sales_data(std::string s) : Sales_data(s, 0, 0) {}
// 	Sales_data(std::istream &is) : Sales_data() {

// 	}
// };

#include <vector>

class NoDefault {
public:
	// NoDefault() = default;
	NoDefault(int val) : value_(val) {}
private:
	int value_;
};

class C {
public:
	C() : node(0) {}
private:
	NoDefault node;
};

int main() 
{
	// std::vector<NoDefault> vec(10);
	std::vector<NoDefault> v;
	return 0;
}
