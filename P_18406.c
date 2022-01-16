#include <stdio.h>
#include <string.h>

int solution(int n)
{
    int left = 0, right = 0;
    char nstring[10];

    sprintf(nstring, "%d", n);

    printf("Length of string a = %zu \n", strlen(nstring));
    if (strlen(nstring) % 2 == 0)
    {
        for (int i = 0; i < strlen(nstring) / 2; i++)
        {
            left += (int)(nstring[i] - 48);
            right += (int)(nstring[i + (int)(strlen(nstring) / 2)] - 48);
        }
    }

    return left == right ? 1 : 0;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    if (solution(n))
        printf("LUCKY");
    else
        printf("READY");

    return 0;
}