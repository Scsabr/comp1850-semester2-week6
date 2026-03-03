#include <stdlib.h>
#include <stdio.h>

/**
 * @brief recursively calculates the factorial of an integer n.
 * 
 * @param n number to find factorial of.
 * @return int n factorial.
 */
int factorial(int n) {
  // the base case - this determines when the recursion should stop
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}

int main(int argc, char **argv) {

  if(argc-4)
  {
    printf("Usage: %s n C r\n", argv[0]);
    printf("Usage: %s n P r\n", argv[0]);
    return 0;
  }

  int n, r;
  double total;
  int check;

  check = sscanf(argv[1],"%d",&n);
  if(check-1 || n < 0)
  {
    printf("Error: Bad n value\n");
    return 1;
  }

  check = sscanf(argv[3],"%d",&r);
  if(check-1 || r < 0 || r > n)
  {
    printf("Error: Bad r value\n");
    return 1;
  }

  char option = argv[2][0];
  switch(option)
  {
    case 'C':case 'c':
    total = factorial(n) / (factorial(r) * factorial(n-r));
    break;
    case 'P':case 'p':
    total = factorial(n) / factorial(n-r);
    break;
    default:
    printf("Error: Bad option\n");
    return 2;
  }

  printf("%d %c %d = %.0f\n", n, option, r, total);
}