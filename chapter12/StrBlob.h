#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <exception>
// #include "StrBlobPtr.h"

using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;

class StrBlobPtr;

class StrBlob {
public:
	using size_type = vector<string>::size_type;

	friend class StrBlobPtr;

	StrBlobPtr begin();
	StrBlobPtr end();

	StrBlob();
	StrBlob(std::initializer_list<string> il);

	size_type size() const;
	bool empty() const;

	void push_back(const string &t);
	void pop_back();

	string& front();
	string& back(); 

private:
	void check(size_type i, const string &msg) const;

private:
	shared_ptr<vector<string>> data;
};


#endif
