/*
 * 功能:学习MPI C编程
 * 用法: mpicc -o xxx xxx.c   **类似于gcc用法
 * 执行: mpirun -n x ./a.out  **一定要用mpirun运行,n 表示进程的个数
 * time: 2015.12.30
 */

// #include "mip.h"
#include <stdio.h>
#include <mpich/mpi.h>//这样写,可以避免有那些语法错误出现
  
int main(int argc,  char* argv[])  
{  
    int rank;  
    int size;  
    MPI_Init(&argc,&argv);//第一个调用  
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); //获得类似于进程的ID
    MPI_Comm_size(MPI_COMM_WORLD, &size);  //获得进程个数
      
	printf("hello world ! rank: %d, size :%d\n", rank, size);
    MPI_Finalize();  
  
    return 0;  
}  
