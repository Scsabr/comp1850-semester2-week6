#include <stdio.h>

void add(int a, int b, int* answer)
{
    *answer = a + b;
}

int main(void)
{
    int result = 0;
    add(10, 5, &result);
    printf("%d\n", result);
}
