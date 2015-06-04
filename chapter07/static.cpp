#include <iostream>
#include <string>

class Account {
public:
	void calculate() {
		amount += amount * interestRate;
	}
	static double rate() {
		return interestRate;
	}
	static void rate(double);

private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();
};

void Account::rate(double newRate) {
	interestRate = newRate;
}

// double Account::interestRate = 0.1
double Account::initRate() {
	// interestRate = 0.1;
	return 0.1;
}
double Account::interestRate = initRate();

int main()
{
	double r = Account::rate();
	std::cout << r << std::endl;
	return 0;
}
