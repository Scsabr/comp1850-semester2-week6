#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  // argument check to ensure users have entered some numbers.
  if (argc < 2)
  {
    printf("Usage: ./averages num1 ... numx\n");
    return 0;
  }

  // setting up variables for use later in the code

  // array of ints which will hold our arguments
  int *numbers;
  // the number of integers passed into the program (the argc - 1 to account for
  // the function name)
  int count = argc - 1;
  // a buffer for use with fgets() for user input
  char buffer[50];
  // the variable representing the user's choice for the menu
  int choice = 0;
  // to hold the sum of the values
  int total = 0;
  // to hold the average of the values
  float mean;

  // firstly, we will load the args into the numbers array

  // allocate the array:
  numbers = calloc(count, sizeof(int));

  for (int i = 0; i < count; i++)
  {
    // rather than use atoi, sscanf to ensure the arguments are all numeric
    int check = sscanf(argv[i + 1], "%d", &numbers[i]);

    // sscanf() returns the number of values it found - if it does not return 1
    // then a number was not found
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
      for (int i = 0; i < count; i++)
      {
        // using a ternary to decide between a space or a newline
        printf("%d%c", numbers[i], (i == count - 1) ? '\n' : ' ');
      }
      break;
    case 2:
      for (int i = 0; i < count; i++)
      {
        total += numbers[i];
      }
      printf("Total is: %d\n", total);
      break;
    case 3:
      total = 0;
      for (int i = 0; i < count; i++)
      {
        total += numbers[i];
      }
      // C will do integer division unless we cast
      mean = (float)total / count;
      printf("Average is: %.2f\n", mean);
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