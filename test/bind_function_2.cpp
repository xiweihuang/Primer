#include <iostream>
#include <functional>
using namespace std;

// 企鹅能跑、能游泳
class Penguin
{
public:
	void run() {

	}
	void swim() {

	}
};

// 麻雀能飞、能跑
class Sparrow
{
public:
	void fly() {

	}
	void run() {
		
	}
};

typedef function<void()> FlyCallback;
typedef function<void()> RunCallback;
typedef function<void()> SwimCallback;

// 一个既用到run，也用到fly的客户class
class Foo
{
public:
	Foo(FlyCallback flyCb, RunCallback runCb) : flyCb_(flyCb), runCb_(runCb) {}

private:
	FlyCallback flyCb_;
	RunCallback runCb_;
};

// 一个既用到run，也用到swim的客户class
class Bar
{
public:
	Bar(SwimCallback swimCb, RunCallback runCb) : swimCb_(swimCb), runCb_(runCb) {}
private:
	SwimCallback swimCb_;
	RunCallback runCb_;
};

int main()
{
	Sparrow s;
	Penguin p;
	Foo foo(bind(&Sparrow::fly, s), bind(&Sparrow::run, s));
	Bar bar(bind(&Penguin::swim, p), bind(&Penguin::run, p));
}
