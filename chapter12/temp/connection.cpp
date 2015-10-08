#include <stdio.h>
#include <memory>

using namespace std;

struct destination {

};

struct connection {

};

connection connect(destination *pd) {
	printf("打开连接\n");
	return connection();
}

void disconnect(connection c) {
	printf("关闭连接\n");
}

void f(destination &d) {
	printf("直接管理connect\n");
	connection c = connect(&d);

	// 忘记调用disconnect关闭连接

}

void end_connection(connection *p) {
	disconnect(*p);
}

void f1(destination &d) {
	printf("用shared_ptr管理connect\n");
	connection c = connect(&d);
	// shared_ptr<connection> p(&c, end_connection);

	shared_ptr<connection> p(&c, [](connection *p){disconnect(*p);});

}


int main()
{

	return 0;
}
