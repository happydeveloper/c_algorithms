#include <stdio.h>
#include <stdlib.h>

int main()
{
    // n = 홀수
    int n;
    int *arr;
    // 입력받으면 n , n 크기 만큼 정수를 입력받는다.

    scanf("%d", &n);
    arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    printf("%d\n", sum);

    free(arr);

    return 0;
}