#include <iostream>
#include <string>

// class ConstRef {
// public:
// 	ConstRef(int ii);
// private:
// 	int i;
// 	const int ci;
// 	int& ri;
// };

// // ConstRef:ConstRef(int ii) {
// // 	i = ii;
// // 	ci = ii;
// // 	ri = i;
// // }

// ConstRef::ConstRef(int ii) : i(ii), ci(ii), ri(i) {

// }

struct X {
	X(int i, int j) : base(i), rem(base % j) {}
	// int rem, base;
	int base, rem;
};

class Sales_data {
public:
	Sales_data(std::string s = "") : bookNo(s) {
		std::cout << "1---" << std::endl;
	}
	Sales_data(std::string s, unsigned cnt, double rev) : bookNo(s), units_sold(cnt) {
		std::cout << "2---" << std::endl;
	}
	Sales_data(std::istream &is) {
		// std::read(is, *this);
		std::cout << "3---" << std::endl;
	}
private:
	std::string bookNo;
	unsigned units_sold;


};

// Sales_data first_item(std::cin);

int main() 
{
	// Sales_data next;
	Sales_data last("9-999-99999-9");
	return 0;
}

