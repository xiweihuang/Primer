#include <memory>
#include <string>

using namespace std;

void init() {
	// unique_ptr<double> p1;
	// unique_ptr<int> p2(new int(42));

	unique_ptr<string> p1(new string("Stegosaurus"));
	// unique_ptr<string> p2(p1);
	// unique_ptr<string> p3;
	// p3 = p1;

	unique_ptr<string> p2(p1.release());
	unique_ptr<string> p3(new string("Trex"));
	p2.reset(p3.release());  // p3放弃对指针的控制器，并返回指针。 p2指向该内置指针指向的对象

	unique_ptr<string> p4(new string("Kobe"));
	auto pp = p4.release();
	delete pp;
}

void exercise() {
	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	typedef unique_ptr<int> IntP;

	// IntP p0(ix);  // ix不是一个指针类型
	// IntP p1(pi);  // ok...
	IntP p2(pi2); // ok...
	// IntP p3(&ix); // ok...
	// IntP p4(new int(2048)); // ok...
	IntP p5(p2.get()); // error, 赋值拷贝了 
}

int main()
{
	// init();
	exercise();
	return 0;
}
