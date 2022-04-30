#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[])
{
	int tc = strtol(argv[1],NULL,10);
	double n;
	double sum = 0;
	double s;
	omp_set_num_threads(tc);
	printf("Number: ");
	scanf("%lf",&n);
	
	#pragma omp parallel
	{
		int id;
		s = omp_get_wtime();
		id = omp_get_thread_num();
		printf("Process: %d\n",id);
		#pragma omp for reduction(+:sum)
			for(int i=0;i<=(int)n;i++){
				printf("i = %d\t",i);
				sum += i;
				printf("sum = %d\n",(int)sum);
				s = omp_get_wtime() - s;
			}
	}
	printf("Sum is %d \n",(int)sum);
		printf("Executed for %lf s\n",s);
	return 0;
}
