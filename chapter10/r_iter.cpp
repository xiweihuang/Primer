// 反向迭代器
#include <stdio.h>
#include <vector>
#include <list>
#include <string>

using namespace std;

void r_iter() {
	vector<int> vec = {0, 1, 2, 3, 4, 5};
	for (auto iter = vec.crbegin(); iter != vec.crend(); ++iter) {
		printf("%d\n", *iter);
	}
}

void exercise_10_34();
void exercise_10_35();
void exercise_10_36();
void exercise_10_37();
void exercise_10_42();

int main()
{
	// r_iter();
	// exercise_10_34();
	// exercise_10_35();
	// exercise_10_36();
	// exercise_10_37();
	exercise_10_42();
	return 0;
}

void exercise_10_34() {
	vector<int> vec = {1, 2, 3, 4, 5};
	for (auto iter = vec.crbegin(); iter != vec.crend(); ++iter) {
		printf("%d\n", *iter);
	}
}

void exercise_10_35() {
	vector<int> vec = {1, 2, 3, 4, 5};
	for (auto iter = --(vec.cend()); iter != --(vec.begin()); --iter) {
		printf("%d\n", *iter);
	}
}

void exercise_10_36() {
	list<int> lst = {0, 1, 2, 3, 4, 5, 0, 6, 7};
	auto iter = find(lst.rbegin(), lst.rend(), 0);
	printf("%d\n", *iter);
	printf("%d\n", *(++iter));
}

void exercise_10_37() {
	vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> lst;
	copy(vec.rbegin()+3, vec.rbegin()+8, back_inserter(lst));
	for (auto &val : lst) {
		printf("%d\n", val);  // 6 5 4 3 2
	}
}

void exercise_10_42() {
	// sort()
	list<string> lst = {"Kobe", "Jordan", "Kobe", "James", "Durcant"};
	lst.sort([](const string &s1, const string &s2){ return s1.size() < s2.size(); });
	lst.unique();
	lst.sort();
	for (auto &val : lst) {
		printf("%s\n", val.c_str());
	}
}








