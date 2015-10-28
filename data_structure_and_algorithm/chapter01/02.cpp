#include <iostream>
using namespace std;

class IntCell
{
public:
	explicit IntCell(int initialValue = 0)
	{
		storedValue = new int(initialValue);
	}

	/*
		三大函数：
		拷贝构造
		拷贝复制
		析构
	*/
	IntCell(const IntCell &rhs) : storedValue(new int(*rhs.storedValue))
	{
	}

	IntCell &operator = (const IntCell &rhs)
	{
		if (this != &rhs) {
			storedValue = new int(*rhs.storedValue);
		}
		return *this;
	}

	~IntCell()
	{
		if (storedValue) {
			delete storedValue;
			storedValue = NULL;
		}
	}

	int read() const
	{
		return *storedValue;
	}

	void write(int x)
	{
		*storedValue = x;
	}
private:
	int *storedValue;
};

int main()
{
	IntCell a(2);
	IntCell b = a;
	IntCell c;

	c = b;
	a.write(4);
	cout << a.read() << endl << b.read() << endl << c.read() << endl;
	return 0;
}