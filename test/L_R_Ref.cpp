#include <iostream>

using namespace std;

void fun(MyString)

int main()
{

	return 0;
}



void fun(MyString &str)
{
    cout << "left reference" << endl;
}

void fun(MyString &&str)
{
    cout << "right reference" << endl;
}

int main() { 
    MyString a("456"); 
    fun(a); // 左值引用，调用void fun(MyString &str)
    fun(foo()); // 右值引用，调用void fun(MyString &&str)
    return 1;
}