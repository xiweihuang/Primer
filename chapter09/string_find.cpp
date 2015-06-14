// string 搜索操作

// s.find(args)
// s.rfind(args)
// s.find_first_of(args)
// s.find_last_of(args)
// s.find_first_not_of(args)
// s.find_last_not_of(args)

// args必须是以下形式之一:
// c, pos
// s2, pos
// cp, pos
// cp, pos, n

#include <stdio.h>
#include <string>

using namespace std;

void basic() {
	string name("annaBelle");
	auto pos1 = name.find("nna");  // pos1 == npos

	if (pos1 == string::npos)
		printf("pos1 == npos\n");
	else
		printf("%lu\n", pos1);
}

void basic2() {
	string numbers("0123456789");
	string name("ra2d3");
	auto pos = name.find_first_of(numbers);
	printf("%lu\n", pos);

	string name2("123a_fd234632");
	auto pos2 = name2.find_first_not_of(numbers);  // 3
	printf("%lu\n", pos2);
}

void find_start_position() {
	string numbers = "0123456789";
	string name = "5He12llo8World09";
	string::size_type pos = 0;

	while ((pos = name.find_first_of(numbers, pos)) != string::npos) {
		printf("%c\n", name[pos]);
		++pos;
	}
}

int main() 
{
	// basic2();
	find_start_position();
	return 0;
}

// 1. 编写程序，首先查找string "ab2c3d7R4E6"中的每个数字字符，然后查找其中每个字母字符。编写两个版本的程序，第一个要使用find_first_of，第二个要使用find_first_not_of。
// 2. 假定name和numbers的定义如上面所示，numbers.find(name)返回什么？
// 3. 如果一个字母延伸到中线之上，如d或f，则称其有上出头部分。如果一个字母延伸到中线之下，如p或g，则称其有下出头部分。编写程序，读入一个单词文件，输出最长的既不包含上出头部分，也不包含下出头部分的单词。













