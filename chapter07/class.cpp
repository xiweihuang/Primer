#include <iostream>
#include <string>
using namespace std;

struct Sales_data {
	Sales_data() = default;
	Sales_data(const string &s) : bookNo(s) {}
	Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p*n) {}
	Sales_data(istream &);

	string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data &);
	double avg_price() const;

	// 数据成员x
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data &, const Sales_data &);
ostream& print(ostream&, const Sales_data&);
istream& read(istream&, Sales_data&);

int main()
{

	return 0;
}

// ========================================

// #include <iostream>
// #include <string>

// using namespace std;

// class Person {
// public:
// 	Person(const string &n, const string &a) {
// 		name_ = n;
// 		address_ = a;
// 	}
// 	string getName() const {
// 		return name_;
// 	}
// 	string getAddress() const {
// 		return address_;
// 	}
// private:
// 	string name_;
// 	string address_;
// };

// int main()
// {
// 	Person p("Kobe", "LA");
// 	cout << p.getName() << "   " << p.getAddress() << endl;
// 	return 0;
// }

