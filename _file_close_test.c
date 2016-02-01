/**
 * 功能:测试close()
 * 结果:同一进程中close只需用一次
 *      不同进程之间fd引用计数才会增加
 */
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX 10
void fun( int fd){//关闭fd
	char buff[MAX];
	buff[MAX-1] = 0;

	read(fd, buff, MAX-1);
	printf("fun read %s\n", buff);
	close(fd);

}

int main(){
	int fd = -1;
	char buff[MAX];
	int n;

	buff[MAX-1] = 0;

	fd = open("./static.c", O_RDONLY);	
	if(fd < 0){
		perror("open error");
		exit(1);
	}
	n = read(fd, buff, MAX-1);
	if(n<0){
		perror("read error");
		exit(1);
	}

	fun(fd);

	n = read(fd, buff, MAX-1);
	if(n<0){//这里应该会执行,因为fd已经被关闭
		perror("fd is closed and tyr to read error");
		exit(1);
	}

	return 0;
}

