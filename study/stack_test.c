/**
 * 功能:测试函数栈
 * 时间:2015.12.23
 */

#include <stdio.h>
int test(int , int);
int test2();
int test3();


int test2(){
	printf("test 2");
	return 0;
}

int test(int a, int b){
	int sum = a+b;
	printf("sum_addr: %lx\n", (unsigned long) &sum);
	printf("a_addr: %lx\nb_addr: %lx\n",(unsigned long) &a, (unsigned long)&b);
	printf("%d ", *(&sum - 4));

	/*IP  8个字节*/
	printf("ip: %x %x \n", *(&sum+4), *(&sum+3));
	/*IP 不能被修改*/
	*(&sum+0) =(long) test2;
	printf("*(&sum+0) : %d, %d\n", *(&sum+0), sum);
	return 0;
}
int test3() {
	int a __attribute__ ((unused)) = 123;
	char name[25]__attribute__ ((unused));

	return 0;
}
int unusedfun(){
	printf("sdfkjds");
	return 0;
}
int main(){
	int a = 111111;
	int b = 222222;
	printf("main_a: %lx\nmain_b: %lx, %d\n", (unsigned long)&a, (unsigned long)&b , a);
	test(a, b);
//	printf("%d\n", *(&a - 7));
	printf("%lx %lx",(unsigned long) main, (unsigned long)test);
	test2();
	test3();

	return 0;
}




// 698 : 1688
// 69c : 1692
// 67c : 1660
// 66c : 1644
// 668 : 1640
