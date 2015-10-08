#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H

#include <vector>
#include <memory>
#include <initializer_list>
#include <string>

class StrBlob {
public:
	using size_type = std::vector<std::string>::size_type;

	StrBlob();
	StrBlob(std::initializer_list<std::string>& il);

	size_type size() const;
	bool empty() const;

	void push_back(const string &);
	void pop_back();

	std::string& front();
	std::string& back();

	const string& front() const;
	const string& back() const;

	// 提供给StrBlobPtr的接口
	// 定义StrBlobPtr后才能定义这两个函数
	StrBlobPtr begin();
	StrBlobPtr end();


private:
	void check(size_type i, const std::string &msg) const;  // 如果_data[i]不合法，就抛出一个异常
	std::shared_ptr<std::vector<std::string>> _data;
};


class StrBlobPtr
{
public:
	StrBlobPtr();
	StrBlobPtr();
};

#endif


