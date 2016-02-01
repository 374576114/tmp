/*
 * 功能：学习叫醒睡眠中的进程
 * 信号：SIGALRM 
 * 函数：alarm(int sec);
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void sig(int num){
	pid_t pid;
	int stat;

	while((pid = waitpid(-1, &stat, WNOHANG))> 0)
	printf("wait for child\n");

	return ;
}
void sig_sleep(int num){
	printf("will be end\n");
}
void sig_wakup(int num){
	printf("alrm is here\n");
}

int main(){
	int i=0;

	//signal(SIGCHLD, sig);
	signal(SIGINT, sig_sleep);
	signal(SIGALRM, sig_wakup);
	alarm(2);

	while(i<10){
		printf("sleep....\n");
		sleep(20);
		i++;
	}
	/*
	for(i=0; i<10; i++){
		if(fork() == 0){
			break;
		}
	}
	*/
	return 0;
}
