#include <stdio.h>

union test{
	float a;
	char b[4];
}a;

int main(){
	char *p = NULL;
	int i;

	//a.a = 0.0f;
	a.a = 20.59375f;
	p = a.b;
	for(i=0; i<4; i++){
		printf("%x ", (unsigned int)*(p+i));
	}

	return 0;
}

