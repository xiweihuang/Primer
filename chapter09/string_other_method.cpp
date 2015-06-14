// 改变string的其他方法
// 支持顺序容器的assign、insert和erase
// 除此之外，还定义了额外的insert和erase版本

#include <stdio.h>
#include <string>

using namespace std;

// insert 和 replace 等操作，于 string 来说，经常用的应该是下标运算，所以应主要熟悉下标的运算
// 而且再仔细观察，会发现 insert 和 replace 的args都是一样的！！！

// 而普通的顺序容器都有 insert 操作，所以对于 string 的迭代器版本的 insert， 应该遵守普通顺序容器的 insert 规则
// 而 replace 操作是 string 特有的，所以可以支持多种参数的形式，除开 str, pos, len 形式，其他都支持

// ================== insert =====================
// 1. insert(pos, args)  返回引用
// args可以是:
// str
// str, pos, len
// cp, len
// cp
// n, c

// 2. insert(iter, args) 返回迭代器
// args可以是:
// n, c
// b2, e2
// 初始化列表{...}
void insert1() {
	string str  = "Kobe";

	string str2 = "Nba";
	str.insert(0, str2);  // NbaKobe

	string str3 = "2015NBA";
	str.insert(str.size(), str3, 0, 4); // NbaKobe2015

	const char *cp = "ActionTime";
	str.insert(3, cp, 6);
	str.insert(3, cp+6);  // NbaTimeActionKobe2015

	str.insert(0, 5, '=');

	printf("%s\n", str.c_str());
}

void insert2() {
	string str = "Jordan";

	string str2 = "Michael";
	str.insert(str.begin(), str2.begin(), str2.end());  // MichaelJordan

	str.insert(str.end(), 5, '=');  // MichaelJordan=====

	str.insert(str.begin(), {'a', 'b'});  // abMichaelJordan=====

	printf("%s\n", str.c_str());
}

// ================== replace =====================
// 1. replace(pos, len, args)
// str
// str, pos, len
// cp, len
// cp
// n, c

// 2. replace(b, e, args)
// str
// cp, len
// cp
// n, c
// b2, e2
// 初始化列表{...}

void replace1() {
	string str = "KobeBryant";
	str.replace(4, 6, "Jordan");  // KobeJordan

	str.replace(0, 4, "MichaelJack", 0, 7); //MichaelJordan

	const char *cp = "TimDurcant";
	str.replace(0, 7, cp, 3);  // TimJordan

	const char *cpp = "Durcant";
	str.replace(3, 6, cpp);  // TimDurcant

	str.replace(0, 0, 5, '=');  // =====TimDurcant

	printf("%s\n", str.c_str());
}

void replace2() {
	string str = "Michael Jordan";
}


int main()
{
	// insert1();
	// insert2();
	replace1();
	return 0;
}


// 1. 编写一个函数，接受三个string参数s、oldVal和newVal。使用迭代器及insert和erase函数将s中所有oldVal替换为newVal。测试你的程序，用它替换通用的简写形式，如，将"tho"替换成"though"，将"thru"替换为"through"。
// 2. 重写上一题的函数，这次使用一个下标和replace。
// 3. 编写一个函数，接受一个表示名字的string参数和两个分别表示前缀(如"Mr."或"Ms.")及后缀(如"Jr."或"III")的字符串。使用迭代器及insert和append函数将前缀和后缀添加到给定的名字中，将生成的新string返回。
// 4. 重写上一题的函数，这次使用位置和长度来管理string，并只使用insert。











