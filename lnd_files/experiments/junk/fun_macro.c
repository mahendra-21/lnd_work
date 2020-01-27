#include <stdio.h>

#define SQR(s)  ((s) * (s))

#define PRNT(a,b) \
  printf("value 1 = %d\n", a); \
  printf("value 2 = %d\n", b);

#define X(a, b) X(a + 1, b + 1) + 4

int main(void)
{
      int x = 2;
      int y = 3;

      PRNT(SQR(x),y);

      printf("X = %d\n", X(x, y));      
      return 0;
}
