#include "StrBlob.h"
#include "StrBlobPtr.h"


StrBlobPtr::StrBlobPtr() : curr(0) {

}
StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {  // 为了访问data成员，要设置友元

}  

string& StrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

// bool operator!=(const StrBlobPtr& p) {return p.curr != curr; }



shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if ( i >= ret->size())
		throw  std::out_of_range(msg);
	return ret;
}
