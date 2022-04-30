#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define DIM 10
bool P[DIM+1];

void eratosten(int n){
		int id;
		id = omp_get_thread_num();
		printf("Process: %d\n",id);
		for(int i=2;i<sqrt(n);i++){
			if(P[i]){
				#pragma omp parallel for reduction (*:P[i]) schedule (static,2)
				for(int j=i;j<n;j++){
					P[i*j]=false;
				}
			}
		}
}

int main(int argc, char* argv[])
{
	int n;
	double s;
	int tc = strtol(argv[1],NULL,10);
	omp_set_num_threads(tc);
	n = atoi(argv[2]);
	printf("Number: %d\n",n);
	for(int i=1;i<n;i++){
		P[i]=true;
	}
	
	s = omp_get_wtime();
	
	eratosten(n);
		
	printf("Prime numbers: ");
	for(int i=1;i<=n;i++){
		if(P[i]){
			printf("%d ",i);
		}
	}
	
	s = omp_get_wtime() - s;
	printf("\nExecuted for %lf s\n",s);
		
	return 0;
}
