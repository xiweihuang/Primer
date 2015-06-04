#include <iostream>
#include <string>

using namespace std;

typedef string::size_type pos;

class MyScreen {
public:
	MyScreen() = default;
	MyScreen(pos width, pos height, unsigned space_num);
	// MyScreen(pos width, pos height, char c) : _width(width), _height(height), contents(string(1, c)) {}
	MyScreen(pos width, pos height, char c);
private:
	pos _width = 0, _height = 0;
	string contents;
};

MyScreen::MyScreen(pos width, pos height, unsigned space_num) : _width(width), _height(height) {
	contents = string(space_num, ' ');
}

MyScreen::MyScreen(pos width, pos height, char c) {
	_width = width;
	_height = height;
	contents = c;
}

int main()
{

	return 0;
}