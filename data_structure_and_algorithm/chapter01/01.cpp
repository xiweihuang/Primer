#include <stdio.h>
// using namespace std;

class IntCell
{
public:
	// IntCell()
	// {
	// 	storedValue = 0;
	// }

	// 必须使用初始化列表的情况：
	// 1.const的数据成员
	// 2.引用类型的数据成员

	// explicit，所有的单参数的构造函数都必须是explicit的，以避免后台的类型转换
	// 使用explicit意味着单参数构造函数不能用来创建隐式临时对象
	explicit IntCell(int initialValue = 0) : storedValue(initialValue)
	{
	}

	~IntCell() {}

	IntCell(const IntCell &rhs) : storedValue(rhs.storedValue) {}
	const IntCell &operator=(const IntCell &rhs)
	{
		if (this != &rhs) {
			storedValue = rhs.storedValue;
		}
		return *this;
	}

	int read() const
	{
		return storedValue;
	}

	void write(int x)
	{
		storedValue = x;
	}
private:
	int storedValue;
};

int main()
{
	// IntCell *m = new IntCell();
	IntCell *m = new IntCell;  // 两种方式都是等价的，但是可能上面一种写法会误认为是函数声明，所以一般用这种方法
	m->write(5);
	printf("Cell contents: %d\n", m->read());
	delete m;
	return 0;
}