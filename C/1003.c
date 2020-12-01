#include <stdio.h>
int fibonacci(int n,int *p,int *q) {
    if (n == 0) {
        *p++;
        return 0;
    } else if (n == 1) {
        *q++;
        return 1;
    } else {
      int c;
      c = fibonacci(n