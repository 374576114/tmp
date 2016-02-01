#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(){

	char str[100];
	
	printf("please input some thing: ");
	scanf("%s", str);

	if(strlen(str) >= 100){
		perror("input error\n");
		exit(1);
	}
	system(str);

	return 0;
}


