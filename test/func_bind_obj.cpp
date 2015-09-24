#include <iostream>
#include <functional>

using namespace std;

class Bird
{
public:
	// virtual void fly() {
	// 	cout << "fly..." << endl;
	// }
	void fly() {
		cout << "fly..." << endl;
	}
};

// class Penguin : public Bird
// {
// public:
// 	void fly() {
// 		cout << "penguin fly..." << endl;
// 	}
// };

class Penguin
{
public:
	// auto fly = bind(&Bird::fly, )
}

int main()
{
	Penguin p;
	p.fly();
	return 0;
}
