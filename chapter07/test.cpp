#include <iostream>
class X;
class Y;

class X {
public:
	Y *py;
	void printx() {
		std::cout << "this is x..." << std::endl;
	}
};

class Y {
public:
	X ox;
};

int main()
{
	return 0;
}