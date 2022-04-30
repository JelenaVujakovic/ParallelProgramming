#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(int argc,char *argv[])
{
	int i,j;
	int n=4;
	int m=1;
	int matrix_a[n];
	int matrix_b[n];
	int matrix_c[m];
	int prank,csize;
	int NRPE;
	double starttime,endtime;
	
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&prank);
	MPI_Comm_size(MPI_COMM_WORLD,&csize);
	MPI_Status status;
	
	if(prank == 0)
	{
		srandom(time(NULL));
		
		for(i=0;i<n;++i){
			matrix_a[i] = rand() % 10;
		}
		printf("Matrix A: [");
		for(i=0;i<n;++i)
		{
			printf("%d ",matrix_a[i]);
		}
		printf("]\n");
		
		for(j=0;j<n;++j)
		{
			matrix_b[j] = rand() % 10;
		}
		printf("Matrix B: [");
		for(j=0;j<n;++j)
		{
			printf("%d ",matrix_b[j]);
		}
		printf("]\n");
	}
	//Broadcast Matrix B values to all processes
	for(i=0;i<n;i++)
	{
		MPI_Bcast(&matrix_b[i],n,MPI_INT,0,MPI_COMM_WORLD);
	}
	
	//Sending row of Matrix A to all processes
	for(i=0;i<csize;i++)
	{
		MPI_Send(&matrix_a[i],n,MPI_INT,i,0,MPI_COMM_WORLD);
	}

	//Receiving row of Matrix A per process
	MPI_Recv(matrix_a,n,MPI_INT,0,0,MPI_COMM_WORLD,&status);

	//Multiplication Area
	starttime = MPI_Wtime();
	
	matrix_c[0] = 0;
	for(i=0;i<n;i++)
	{
		matrix_c[0] += matrix_a[i] * matrix_b[i];
	}
	endtime = MPI_Wtime();
	
	MPI_Send(&matrix_c[0],n,MPI_INT,0,0,MPI_COMM_WORLD);
	
	
	//Display
	if(prank == 0)
	{
		printf("Result Matrix C: [%d]\n", matrix_c[0]);
		printf("Parallel Time %f seconds.\n",endtime-starttime);
	}
	
	MPI_Finalize();
	return 0;
}
	
	
	
	
	
	
