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
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void print_container(const T &t) {
	for (auto &val : t) {
		cout << val << endl;
	}
}

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

void exercise1();
void exercise1_1();

int main() 
{
	// basic2();
	// find_start_position();
	// exercise1();
	exercise1_1();
	return 0;
}

// 1. 编写程序，首先查找string "ab2c3d7R4E6"中的每个数字字符，然后查找其中每个字母字符。编写两个版本的程序，第一个要使用find_first_of，第二个要使用find_first_not_of。
void getAlpAndNumbers(string &alp, string &numbers) {
	vector<char> vc;
	for (int i = 0; i != 26; ++i) {
		vc.push_back('a'+i);
		vc.push_back('A'+i);
	}
	alp.assign(vc.begin(), vc.end());
	numbers = "0123456789";
}

void exercise1() {
	string str = "ab2c3d7R4E6";

	vector<char> vc;
	for (int i = 0; i != 26; ++i) {
		vc.push_back('a'+i);
		vc.push_back('A'+i);
	}
	string alp(vc.begin(), vc.end());
	string numbers("0123456789");

	string::size_type pos = 0;
	vector<char> chArr;
	vector<char> numArr;
	while ((pos = str.find_first_of(numbers, pos)) != string::npos) {
		numArr.push_back(str[pos]);
		++pos;
	}

	pos = 0;
	while ((pos = str.find_first_of(alp, pos)) != string::npos) {
		chArr.push_back(str[pos]);
		++pos;
	}

	print_container(chArr);
	printf("=======\n");
	print_container(numArr);
	
}

void exercise1_1() {
	string str = "ab2c3d7R4E6";

	vector<char> vc;
	for (int i = 0; i != 26; ++i) {
		vc.push_back('a'+i);
		vc.push_back('A'+i);
	}
	string alp(vc.begin(), vc.end());
	string numbers("0123456789");

	string::size_type pos = 0;
	vector<char> chArr;
	vector<int> numArr;
	while ((pos = str.find_first_not_of(alp, pos)) != string::npos) {
		numArr.push_back(str[pos] - '0');
		++pos;
	}

	pos = 0;
	while ((pos = str.find_first_not_of(numbers, pos)) != string::npos) {
		chArr.push_back(str[pos]);
		++pos;
	}

	print_container(chArr);
	printf("----------\n");
	print_container(numArr);

}

// void exercise1_2() {
// 	string str = "ab2c3d7R4E6";

// 	string alp, numbers;
// 	getAlpAndNumbers(alp, numbers);

// 	string::size_type pos1 = 0, pos2 = 0;
// 	vector<char> chArr;
// 	vector<int> numArr;
// 	while (true) {

// 	}
// }

// 2. 假定name和numbers的定义如上面所示，numbers.find(name)返回什么？

// 3. 如果一个字母延伸到中线之上，如d或f，则称其有上出头部分。如果一个字母延伸到中线之下，如p或g，则称其有下出头部分。编写程序，读入一个单词文件，输出最长的既不包含上出头部分，也不包含下出头部分的单词。













