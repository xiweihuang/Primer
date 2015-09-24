#include <iostream>

using namespace std;

class MyString {
public: 
    MyString() { 
        _data = nullptr; 
        _len = 0; 
        printf("Constructor is called!\n");
    } 

    // 移动构造函数的调用时机为用来构造临时变量和用临时变量来构造对象的时候移动语义会被调用
    MyString(MyString &&str) {
        cout << "Move Constructor is called! src: " << (long)str._data << endl;
        _len = str._len;
        _data = str._data;
        str._data = nullptr;
    }

    MyString(const char* p) { 
        _len = strlen (p); 
        _init_data(p); 
        cout << "Constructor is called! this->_data: " << (long)_data << endl;
    } 

    MyString(const MyString& str) { 
        _len = str._len; 
        _init_data(str._data); 
        cout << "Copy Constructor is called! src: " << (long)str._data << " dst: " << (long)_data << endl;
    }

    ~MyString() { 
        if (_data)
        {
            cout << "DeConstructor is called! this->_data: " << (long)_data << endl; 
            free(_data);
        }
        else
        {
            std::cout << "DeConstructor is called!" << std::endl; 
        }
    } 

    MyString& operator=(const MyString& str) { 
        if (this != &str) { 
            _len = str._len; 
            _init_data(str._data); 
        } 
        cout << "Copy Assignment is called! src: " << (long)str._data << " dst" << (long)_data << endl; 
        return *this; 
    } 

    operator const char *() const {
        return _data;
    }

private: 
    char *_data; 
    size_t   _len; 

    void _init_data(const char *s) { 
        _data = new char[_len+1]; 
        memcpy(_data, s, _len); 
        _data[_len] = '\0'; 
    } 
}; 

MyString foo()
{
    MyString middle("123");
    return middle;
}

void pre_main()
{
    MyString a = foo(); 
}

int main() { 
    cout << endl;
    pre_main();
    cout << endl;
    return 1;
}