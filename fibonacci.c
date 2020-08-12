#include <stdio.h>
#include <omp.h>
 
int main()
{
  int n, a[100], i;

  omp_set_num_threads(2);
 
  printf("Enter the number of Fibonacci numbers to be generated : \n > ");
  scanf("%d", &n);
 
  a[0] = 0; a[1] = 1;
 
  
    for (i = 2; i < n; i++) {
      a[i] = a[i-1] + a[i-2];
      printf("Computation of Fibonacci number %d, thread_id is %d\n", i, omp_get_thread_num());
    }
   
   
    {
      printf("The elements of the fibonacci series are : \n");
      for (i = 0; i < n; i++) {
        printf("%d, thread_id is %d\n", a[i], omp_get_thread_num());
      }
    }
  }  
 
  return 0;
}
