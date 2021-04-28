#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void sum(int n , double*global_result_p);
int main(int argc,char* argv[])
{double global_result =  0.0;
int n;
int thread_count; 

thread_count = strtol(argv[1],NULL,10);
printf("Enter n\n");
scanf("%d",&n);
# pragma opm parallel num_threads(4)
sum(n,&global_result);
printf("the result:%lf",global_result);
return 0;


}
void sum(int n ,double*global_result_p) 
{int my_rank = omp_get_thread_num();
int thread_count = omp_get_num_threads();
int h;
h = n/ thread_count ;
int my_result=0 ;
for(int i = my_rank*h+1;i<=(my_rank+1)*h ;i++)
 { my_result = my_result + i ;
  }
#pragma omp critical
*global_result_p += my_result ;
}


