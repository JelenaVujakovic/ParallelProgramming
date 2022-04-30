#include <stdio.h>
#include <mpi.h>

int main(int argc,char* argv[])
{
	double n;
	double sum = 0;
	int csize, prank;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&csize);
	MPI_Comm_rank(MPI_COMM_WORLD,&prank);

	if(prank == 0)
	{
		if(argc == 2){
			n = atoi(argv[1]);
			printf("\nNumber: %d\n\n",(int)n); 
		}
	}

	MPI_Bcast(&n,1,MPI_DOUBLE,0,MPI_COMM_WORLD);
	printf("Process %d:\n",prank);

	double s = MPI_Wtime();
	double i = (double)prank;
	double ds = (double)csize;
	int temp=0;

	while(i<=n)
	{
		if(prank==0 && i>=csize)
			break;

		if(i<csize && prank > 0){
				i = ds*i;
		}
		sum += i;
		printf("Sum = %f, i = %f, ds = %f \n",sum,i,ds);
		if(i>=7 && prank ==1){
				break;
		}
		if(i>=7 && prank ==1){
				break;
		}
		if(i>=11 && prank ==2){
				break;
		}
		i++;
		temp += 1;
	}
	double tsum;
	MPI_Reduce(&sum,&tsum,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);

	double e = MPI_Wtime();
	double d = e - s;
	double mind;
	MPI_Reduce(&d,&mind,1,MPI_DOUBLE,MPI_MAX,0,MPI_COMM_WORLD);

	if(prank == 0)
	{
		printf("\nSum of first %d integer is %d\n",(int)n,(int)tsum);
		printf("Elapsed time: %f \n",d);
	}

	MPI_Finalize();
	return 0;
}

