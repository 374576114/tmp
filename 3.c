/*
 * 功能：测试堆栈之间的差距
 */

#include <stdlib.h>
#include <stdio.h>

int main(){
	int addr = 0;
	int *p = NULL;
	long a1, a2;

	p = (int *)calloc(1, sizeof(int));

	a1 = (long) &addr;
	a2 = (long) p;

	printf("%lx %lx\n", a1, a2);

	return 0;
}

