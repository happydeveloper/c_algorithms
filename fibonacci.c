#include <stdio.h>

int solution(int n)
{
    int answer = 0;
    if (n == 0)
        return answer;
    else if (n == 1)
        return answer = 1;
    else
        return solution(n - 1) + solution(n - 2);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("fibonacci %d = %d", n, solution(n));
    return 0;
}