#include <stdio.h>
#include <time.h>

int main(){
	time_t time_sec;

	time(&time_sec);

	printf("%s\n", ctime(&time_sec));

	return 0;
}
