#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

void broadcast(int prank, int csize);

int main(int argc, char **argv)
{
	int csize;
	int prank;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&csize);
	MPI_Comm_rank(MPI_COMM_WORLD,&prank);

	broadcast(prank,csize);

	MPI_Finalize();
}

void broadcast(int prank, int csize)
{
	MPI_Status status;
	int rand_val[csize];
	int rand_temp;
	srandom(time(NULL) + prank);
	rand_temp = random() % 10;

	for(int i=0;i<csize;i++){
		if(i!=prank){
			MPI_Send((void*)&rand_temp,1,MPI_INT,i,1,MPI_COMM_WORLD);
		}
	}
	
	for(int i=0;i<csize;i++){
		if(i!=prank){
			MPI_Recv((void*)&rand_temp,1,MPI_INT,i,1,MPI_COMM_WORLD,&status);
			rand_val[i]=rand_temp;
		}
	}	
	printf("Proces %d received: ",prank);
	for(int i=0;i<csize;i++){
		if(i!=prank){
			printf("%d%d ",i,rand_val[i]);
		}
	}
	printf("\n");
}


