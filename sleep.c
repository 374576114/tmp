#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int n = 10;
void sleep_thread(void){
	sleep(n);
	printf("sleep end \n");
}

void wake_thread(void){
	printf("wake \n");
	n = 0;
}

int main(){
	pthread_t p1, p2;

	pthread_create(&p1, NULL, (void *)&sleep_thread, NULL);
	sleep(1);
	pthread_create(&p2, NULL, (void *)&wake_thread, NULL);

	pthread_join(p1, NULL);
	pthread_join(p2, NULL);

	printf("all end\n");

	return 0;
}
