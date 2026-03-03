#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Prints all values from the numbers array
 *
 * @param count number of values in the array
 * @param numbers the array of values
 */
void print_all(int count, int *numbers) {
  for (int i = 0; i < count; i++) {
    printf("%d%c", numbers[i], (i == count - 1) ? '\n' : ' ');
  }
}

/**
 * @brief calculates and returns the sum of values in an array
 *
 * @param count the number of values in numbers
 * @param numbers the array
 * @return int the sum of values
 */
int sum_all(int count, int *numbers) {
  int total = 0;

  for (int i = 0; i < count; i++) {
    total += numbers[i];
  }

  return total;
}

/**
 * @brief Calculates the mean average of values in an array
 *
 * @param count the number of values in the array
 * @param numbers the array
 * @return float the mean average of the values
 */
float average_all(int count, int *numbers) {
  // re-using sum_all()
  int total = sum_all(count, numbers);

  return (float)total / count;
}

/**
 * @brief finds the maximum number in the array
 * 
 * @param count size of array
 * @param numbers array of ints
 * @return int the largest value in the array
 */
int max(int count, int* numbers)
{
  int current = -1;
  for (int i=0; i< count; i++)
  {
    current = (numbers[i]>current)?numbers[i]:current; 
  }
  return current;
}

/**
 * @brief finds the smallest value in an array
 * 
 * @param count size of array
 * @param numbers array of integers
 * @return int the smallest value in the array
 */
int min(int count, int* numbers)
{
  int current = 99999999999;
  for (int i=0; i< count; i++)
  {
    current = (numbers[i]<current)?numbers[i]:current; 
  }
  return current;
}

/**
 * @brief Finds the range of the array (max - min)
 * 
 * @param count size of array
 * @param numbers array of ints
 * @return int the max - min
 */
int range(int count, int* numbers)
{
  return max(count, numbers) - min(count, numbers);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: ./averages num1 ... numx\n");
    return 0;
  }

  int *numbers;
  int count = argc - 1;
  char buffer[50];
  int choice = 0;
  int total = 0;
  float mean;
  int maximum, minimum, numrange, mode, median;

  numbers = calloc(count, sizeof(int));

  for (int i = 0; i < count; i++) {
    int check = sscanf(argv[i + 1], "%d", &numbers[i]);

    if (check != 1) {
      printf("Error: Non-numerical Argument\n");
      return 1;
    }
  }

  do {
    printf("1 - Show all values\n");
    printf("2 - Calculate sum\n");
    printf("3 - Calculate mean\n");
    printf("4 - Calculate max\n");
    printf("5 - Calculate min\n");
    printf("6 - Calculate range\n");
    printf("10 - exit\n");

    printf("Enter choice: ");
    fgets(buffer, sizeof(buffer), stdin);
    int check = sscanf(buffer, "%d ", &choice);

    if (check != 1) {
      printf("Error: Invalid choice\n");
      continue;
    }

    switch (choice) {
    case 1:
      print_all(count, numbers);
      break;
    case 2:
      total = sum_all(count, numbers);
      printf("Total is: %d\n", total);
      break;
    case 3:
      mean = average_all(count, numbers);
      printf("Average is: %.2f\n", mean);
      break;
    case 4:
      maximum = max(count, numbers);
      printf("Maximum is: %d\n", maximum);
      break;
    case 5:
      minimum = min(count, numbers);
      printf("Minimum is: %d\n", minimum);
      break;
    case 6:
      numrange = range(count, numbers);
      printf("Range is: %d\n", numrange);
      break;
    case 10:
      printf("Exiting...\n");
      break;
    default:
      printf("Error: Invalid choice\n");
      break;
    }
  } while (choice!=10);

  return 0;
}