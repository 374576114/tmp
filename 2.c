/*
 * 测试:malloc(0)
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	char *p = NULL;

	p = (char*)malloc(0);

	strcpy(p, "addddbc");
	printf("%s\n", p);

	free(p);

	printf("dddd:\n");
	return 0;
}
