#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef string::size_type pos;

class Screen {
public:
	
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) {}
	char get() const 
	{
		return contents[cursor];
	}
	inline char get(pos ht, pos wd) const;
	Screen& move(pos r, pos c);

	void some_member() const;
	void print_member() const {
		cout << access_ctr << endl;
	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;

	mutable size_t access_ctr = 0;
	// size_t access_ctr = 0; // 非可变数据成员，编译器会报错
};

char Screen::get(pos r, pos c) const {
	pos row = r*width;
	return contents[row+c];
} 

inline Screen& Screen::move(pos r, pos c) {
	pos row = r*width;
	cursor = row + c;
	return *this;
}

void Screen::some_member() const {
	++access_ctr;
}

// ===== Window_mgr
class Window_mgr {
private:
	std::vector<Screen> screens{Screen()};
};

int main()
{
	Screen s;
	s.some_member();
	s.print_member();
	return 0;
}