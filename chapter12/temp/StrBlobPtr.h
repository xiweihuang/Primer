#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include "StrBlob.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

// class StrBlob;

class StrBlobPtr {
public:

	StrBlobPtr();
	StrBlobPtr(StrBlob &a, size_t sz = 0);

	string& deref() const;

	StrBlobPtr& incr();

	bool operator!=(const StrBlobPtr& p) {return p.curr != curr; }


private:
	std::shared_ptr<vector<string>> check(size_t i, const string &msg) const;
	std::weak_ptr<vector<string>> wptr;
	size_t curr;
};

#endif
