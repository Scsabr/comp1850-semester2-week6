#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Prints all values from the numbers array
 *
 * @param count number of values in the array
 * @param numbers the array of values
 */
void print_all(int count, int *numbers)
{
  for (int i = 0; i < count; i++)
  {
    printf("%d%c", numbers[i], (i == count - 1) ? '\n' : ' ');
  }
}

float calculate(int count, int *numbers, int choice)
{
  float total = 0;
  for (int i = 0; i < count; i++)
  {
    total += numbers[i];
  }

  if (choice == 2)
  {
    return total;
  }
  else if (choice == 3)
  {
    return (total / count);
  }
}

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("Usage: ./averages num1 ... numx\n");
    return 0;
  }

  int *numbers;
  int count = argc - 1;
  char buffer[50];
  int choice = 0;
  int total = 0;
  float mean;

  numbers = calloc(count, sizeof(int));

  for (int i = 0; i < count; i++)
  {
    int check = sscanf(argv[i + 1], "%d", &numbers[i]);

    if (check != 1)
    {
      printf("Error: Non-numerical Argument\n");
      return 1;
    }
  }

  do
  {
    printf("1 - Show all values\n");
    printf("2 - Calculate sum\n");
    printf("3 - Calculate mean\n");
    printf("4 - exit\n");

    printf("Enter choice: ");
    fgets(buffer, sizeof(buffer), stdin);
    int check = sscanf(buffer, "%d ", &choice);

    if (check != 1)
    {
      printf("Error: Invalid choice\n");
      continue;
    }

    switch (choice)
    {
    case 1:
      print_all(count, numbers);
      break;
    case 2:
    case 3:
      printf("Answer: %.2f\n", calculate(count, numbers, choice));
      break;
    case 4:
      printf("Exiting...\n");
      break;
    default:
      printf("Error: Invalid choice\n");
      break;
    }
  } while (choice != 4);

  return 0;
}
