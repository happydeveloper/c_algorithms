#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  clock_t start, finish;
  double duration;
  start=clock();
  for(int i =0; i < 10; i++){
    for(int j =0; j< 3000; j++)
     printf("%d", j); 
  }

  finish = clock();
  duration = (double) (finish-start) / CLOCKS_PER_SEC;

  printf("%f 초 \n", duration);
  return 0;
}
