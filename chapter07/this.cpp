#include <iostream>
#include <string>

using namespace std;

// 左右值
// 简单归纳：当一个对象被用作右值的时候，用的是对象的值（内容）；当对象被用作左值的时候，用的是对象的身份（在内存中的位置）

class Screen {
public:
	// typedef string::size_type pos;
	using pos = string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) {}
	char get() const {
		return contents[cursor];
	}
	inline char get(pos ht, pos wd) const;
	Screen& move(pos r, pos c);
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
};

inline Screen& Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

char Screen::get(pos ht, pos wd) const {
	pos row = r * width;
	return contents[row + c];
}

int main()
{

	return 0;
}