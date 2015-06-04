#include <stdio.h>

// void print(int a)
// {
// 	printf("111:%d", a);
// }

void print(int a, int b)
{
	printf("222:%d, %d", a, b);
}

int main()
{
	print(1, 2);
	return 0;
}