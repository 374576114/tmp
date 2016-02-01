/*
 * 功能:学习信号的使用
 * 原型: void (*signal(int signo, void (*fun)(int)))(int)
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#define MAX_LEN 100
#define FILE_PATH "/dev/stdin"

int fd;

void input_handler(int num){
	char data[MAX_LEN];
	int len;

	len = read(fd, &data, MAX_LEN);
	data[len] = 0;

	printf("input available: %s\n", data);
}

int main(){
	int oflags;

	fd = open(FILE_PATH, O_RDWR , S_IRUSR | S_IWUSR);

	if(fd == -1){
		printf("error\n");
		exit(0);
	}

	signal(SIGIO, input_handler);
	fcntl(fd, F_SETOWN , getpid());
	oflags = fcntl(fd, F_GETFL);;
	fcntl(fd, F_SETFL, oflags | FASYNC);

	while(1);

	return 0;
}
