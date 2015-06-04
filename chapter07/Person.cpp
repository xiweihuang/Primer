#include <iostream>
#include <string>

using namespace std;

class Person {
	friend void read();
public:
	Person(const string &name, const string &address) : _name(name), _address(address) {}

	string getName() const {
		return _name;
	}
	string getAddress() const {
		return _address;
	}

private:
	string _name;
	string _address;
};

void read() {
	Person p("Jordan", "American");
	cout << p._name << " " << p._address << endl;
}


int main()
{
	// Person p("Kobe", "LA");
	// cout << p.getName() << " " << p.getAddress() << endl;
	read();
	return 0;
}