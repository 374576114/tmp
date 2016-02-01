#include <stdio.h>
#include <mpich/mpi.h>
#include <string.h>

int main(int argc, char * argv[]){
	int numprocess, myid, source;
	MPI_Status status;
	char message[100];

	message[100-1] = 0;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);//MPI_COMM_WORLD 通信域
	MPI_Comm_size(MPI_COMM_WORLD, &numprocess);

	if(myid != 0){//其他的进程,非主进程
		strcpy(message, "Hello world");
		MPI_Send(message,strlen(message) + 1, MPI_CHAR, 0, 99,MPI_COMM_WORLD); 
	}else {
		for(source=1; source < numprocess; source ++){
			MPI_Recv(message, 100, MPI_CHAR, source, 99, MPI_COMM_WORLD, &status);
			printf("%s\n", message);
		}
	}
	MPI_Finalize();
}
