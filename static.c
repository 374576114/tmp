//#define NDEBUG
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>
struct student{
	char c;
	int num;
	int mark;
};

int add(int a, int b){

	printf("add: %d\n", a+b);
	return (a+b);
}

int main(){
//	double b = 1;
//	double  a = 0;
//	a = sqrt(b);
//	printf("%lf\n", a);
//	errno = 0;
//	assert(errno == 0);
//	errno = EBUSY;
//	perror("0");
//	printf("%s %d\n", __FILE__,  __LINE__);

	struct student s ={
		.c = 'a',
		.num = 1,
		.mark = 100
	};
	int (*p)(int ,int);
	double a = 1, b = -1;

	p = NULL;


	p (1,2); 
	(*p)(1,3);
	errno = 0;
	a = sqrt(b);
	perror("");

	return 0;
}
