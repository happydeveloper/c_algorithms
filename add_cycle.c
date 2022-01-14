#include <stdio.h>

int solution(int n){
  int j, n_1, n_2, sum=0, cnt=0;
  j = n;
  while(1){
    n_1 = n/10, n_2 = n%10;
    sum = n_1 + n_2;
    if(sum >= 10) sum = sum%10;
    sum = n_2 * 10 + sum;
    if(j == sum) break;
    n=sum;
    cnt++;
  }
  return cnt; 
}
int main() {
  int N;
  scanf("%d", &N );
  printf("%d", solution(N));
  return 0;
}
