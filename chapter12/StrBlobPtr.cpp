#include <memory>
#include <vector>
#include <string>

using namespace std;

class StrBlobPtr {
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	string& deref() const;
	StrBlobPtr& incr();
private:
	shared_ptr<vector<string>> check(size_t, const string &) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;  // 在数组中的当前位置
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t, i, const string &msg) const {
	auto ret = wptr.lock();
	if (ret)
		return ret;
	return nullptr;
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

int main()
{

	return 0;
}
