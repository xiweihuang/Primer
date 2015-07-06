// #include <iostream>
#include <stdio.h>
#include <memory>
#include <string>
#include <vector>

using namespace std;

void makeShared() {
	shared_ptr<int> p3 = make_shared<int>(42);  //int* p = new int(42);
	shared_ptr<string> p4 = make_shared<string>(10, '9');  // string* p = new string(10, '9');
	shared_ptr<int> p5 = make_shared<int>();  // int* p = new int();
	auto p6 = make_shared<vector<string>>();
}

void copy_assign() {
	auto p = make_shared<int>(42);
	auto q(p);
}

class StrBlob {
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	size_type size() const {
		return data->size();
	}
	bool empty() const {
		return data->empty();
	}
	void push_back(const string &t) {
		data->push_back(t);
	}
	void pop_back();
	string& front();
	string& back();
private:
	shared_ptr<vector<string>> data;  // vector<string>* data = new vector<string>();
	void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {

}

StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {

}

void StrBlob::check(size_type i, const string &msg) const {
	if ( i >= data->size()) {
		throw out_of_range(msg);
	}
}

string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

int main() 
{
	// shared_ptr<string> p1;
	// if (p1 && p1->empty()) {
	// 	*p1 = "hi";
	// }
	initializer_list<int> il = {1, 2, 3, 4, 5};
	vector<int> vi(il);
	for (const auto &val : vi) {
		printf("%d\n", val);
	}
	// makeShared();
	return 0;
}
