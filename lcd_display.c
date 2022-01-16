#include <stdio.h>
#include <stdlib.h>

int setCol(int s)
{
  return s + 2;
}

int setRow(int s)
{
  return 2 * s + 3;
}

int lengths(char *str)
{
  int len;
  len = 0;
  while (str[len])
  {
    len++;
  }
  return len;
}

int getIdx(int x, int s)
{
  int oneCharScale = (2 + s);
  return (int)(x / oneCharScale);
}

char *makeArray(char repeat, char start, char teminal, int n)
{
  char *arr = (char *)malloc(sizeof(char) * n);

  for (int i = 0; i < n; i++)
  {
    if (i == 0)
      arr[i] = start;
    else if (i == n - 1)
      arr[i] = teminal;
    else
      arr[i] = repeat;
  }

  return arr;
}

char typeset(int t, int n, int x)
{
  char *newArr;
  if (t == 0)
  {
    //.---.//
    newArr = makeArray('-', '.', '.', n);
  }
  else if (t == 1)
  {
    //|---|//
    newArr = makeArray('-', '|', '|', n);
  }
  else if (t == 2)
  {
    //....|
    newArr = makeArray('.', '.', '|', n);
  }
  else if (t == 3)
  {
    //|....
    newArr = makeArray('-', '|', '.', n);
  }
  else
  {
    //....
    newArr = makeArray('-', '.', '.', n);
  }

  return newArr[x];
}

//맨위 //중간 //맨바닥
char dotPrint(int s, int x, int y, int d)
{
  int width = 2 + s;
  int height = 5;
  char **dot;
  dot = (char **)malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++)
  {
    dot[i] = (char *)malloc(sizeof(char) * width);
  }

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      dot[i][j] = '.'; //types(j);
    }
  }

  int p = x % (2 + s);
  int top, mid, bottom;
  top = 0;
  mid = 1 + s;
  bottom = 2 + (2 * s);

  if (d == 1)
  {
    if (y == top || y == mid || y == bottom)
      return typeset(4, width, x);
    else
      return typeset(2, width, x);
  }
  if (d == 2)
  {
  }
  return (char)d + 48;
}

int main()
{
  int s, c, r, x, y;
  char n[8] = {'0'};
  //입력단
  scanf("%d %s", &s, n);
  printf("%d %s\n", s, n);

  //유효성 체크

  //계산단
  x = setCol(s) * lengths(n);
  y = setRow(s);
  int arr_n[lengths(n)];
  for (int i = 0; i < lengths(n); i++)
    arr_n[i] = (int)n[i] - 48;
  //출력단
  for (int j = 0; j < y; j++)
  {
    for (int i = 0; i < x; i++)
    {
      int v = arr_n[getIdx(i, s)];
      printf("%d", v);
      //printf("%c", dotPrint(s, i, j, v));
    }

    printf("\n");
  }

  return 0;
}
