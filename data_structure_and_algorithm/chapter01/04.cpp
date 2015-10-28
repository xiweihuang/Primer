#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
	void setValue(const string& n, double s)
	{
		name = n;
		salary = s;
	}
	const string& getName() const
	{
		return name;
	}
	void print(ostream& out) const
	{
		out << name << " (" << salary << ")";
	}
	bool operator < (const Employee& rhs) const
	{
		return salary < rhs.salary;
	}

private:
	string name;
	double salary;
};