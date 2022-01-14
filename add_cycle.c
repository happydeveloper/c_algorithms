#include <stdio.h>

int solution(int n){
  int j, cnt=0;
  j = n;
  while(1){
    j  = (j%10) * 10 + ((j/10 + j%10) % 10);
    cnt++;
    if(n == j) return cnt;
  } 
}

int main() {
  int N;
  scanf("%d", &N );
  printf("%d", solution(N));
  return 0;
}
