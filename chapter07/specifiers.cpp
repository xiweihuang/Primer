#include <iostream>
#include <string>

using namespace std;

class Sales_data
{
public:
	Sales_data() = default;
	Sales_data(const string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p*n) {}
	Sales_data(const string &s) : bookNo(s) {}
	~Sales_data();

private:
	double avg_price() const;
	// {
	// 	return units_sold ? revenue/units_sold : 0;
	// }

	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	
};

inline double Sales_data::avg_price() const {
	return units_sold ? revenue/units_sold : 0;
}

int main()
{

	return 0;
}