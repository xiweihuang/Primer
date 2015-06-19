#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 2 2 1 4 4 3 5 3
// 排序，去重

void elimDups(vector<string> &words) 
{
	sort(words.begin(), words.end());
	auto end_iter = unique(words.begin(), words.end());
	words.erase(end_iter, words.end());
}

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	// stable_sort(words.begin(), words.end(), isShorter);
	stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2){ return s1.size() < s2.size(); });

	// 获取一个迭代器，指向第一个满足size() >= sz的元素
	// 计算满足size >= sz的元素的数目
	// 打印长度大于给定值的单词，每个单词后面接一个空格
	auto f = [sz] (const string &a) {
		return a.size() >= sz;
	};
	auto wc = find_if(words.begin(), words.end(), f);

	auto count = words.end() - wc;

	for_each(wc, words.end(), [](const string &s){cout << s << endl;});
}

void test()
{
	// 可以忽略参数列表和返回类型，但必须永远包含捕获列表和函数体
	auto f = [] {
		return 45;
	};
	cout << f() << endl;
}

void exercise_10_14();
void exercise_10_15();
void exercise_10_16();

int main()
{
	// test();

	// vector<string> vs = {"Kobe", "Jordan", "Kobe", "James", "Wade", "Durcant"};
	// biggies(vs, 4);

	// exercise_10_14();
	// exercise_10_15();
	exercise_10_16();
	return 0;
}


void exercise_10_14()
{
	auto getSum = [] (int a, int b) {
		return (a+b);
	};
	cout << getSum(10, 20) << endl;
}

void exercise_10_15()
{
	int a = 10, b = 20;
	auto getSum = [a, b] (int c) {
		return a+b+c;
	};
	cout << getSum(30) << endl;  // 60
}

// 10.16 使用lambda编写你自己版本的biggies
void my_elimDups(vector<string> &words)
{
	// 排序，去重
	sort(words.begin(), words.end(), [](const string &s1, const string &s2){ return s1 > s2; });
	// sort(words.begin(), words.end());
	auto end_iter = unique(words.begin(), words.end());
	words.erase(end_iter, words.end());
}
void my_biggies(vector<string> &words, vector<string>::size_type sz) 
{
	my_elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2){ return s1.size() > s2.size(); });

	// 10.16
	// auto iter = find_if(words.begin(), words.end(), [sz](const string &s){return s.size() < sz;});  // 返回值
	// for (auto ptr = words.begin(); ptr != iter; ++ptr) {
	// 	cout << *ptr << endl;
	// }

	// 10.18 用partition代替find_if
	// auto iter = partition(words.begin(), words.end(), [sz](const string &s){ return s.size() >= sz; });
	// for (auto ptr = words.begin(); ptr != iter; ++ptr) {
	// 	cout << *ptr << endl;
	// }

	// 10.19 用stable_partition
	auto iter = stable_partition(words.begin(), words.end(), [sz](const string &s){ return s.size() >= sz; });
	for (auto ptr = words.begin(); ptr != iter; ++ptr) {
		cout << *ptr << endl;
	}
}

void exercise_10_16()
{
	vector<string> vs = {"Kobe", "Jordan", "Kobe", "James", "Wade", "Durcant"};
	my_biggies(vs, 5);
	
}

// 10.17 重写10.12，在对sort的调用中使用lambda来代替函数compareIsbn
// 10.18 重写biggies，用partition代替find_if
// 10.19 用stable_partition重写前一题的程序，与stable_sort类似，在划分后的序列中维持原有元素的顺序








