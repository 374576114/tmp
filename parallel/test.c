#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <time.h>

int main(int argc, char**argv){
	int b = 0;
	clock_t tstart, tfinsh;
	double t;

	printf("%d \n", INT_MAX);

	tstart = clock();
	while(b>=0){
		b++;
	}
	tfinsh = clock();
	t = (double)(tfinsh - tstart)/ CLOCKS_PER_SEC;
	printf("%d %lfs\n", b, t);
	return 0;
}
