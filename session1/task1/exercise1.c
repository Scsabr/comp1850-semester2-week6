#include <stdio.h>
#include <stdlib.h>

int getInput(char *prompt)
{
  char input[20];
  int out;

  printf("%s", prompt);
  if (fgets(input, sizeof(input), stdin))
  {
    sscanf(input, "%d", &out);
  }
  return out;
}

int calculateFine(int limit, int speed)
{
  int fine;
  int excess_speed = speed - limit;

  // Calculate fine based on how much over the limit
  if (excess_speed <= 10)
  {
    fine = 50;
  }
  else if (excess_speed <= 20)
  {
    fine = 100;
  }
  else
  {
    fine = 200;
  }
  return fine;
}

int main()
{
  int speed_limit, driver_speed, fine = 0;
  char input[20];

  speed_limit = getInput("Enter the speed limit: ");
  driver_speed = getInput("Enter the driver's speed: ");

  // Determine if the driver is speeding
  if (driver_speed > speed_limit)
  {
    fine = calculateFine(speed_limit, driver_speed);
    printf("Fine: $%d\n", fine);
  }
  else
  {
    printf("No fine needed.\n");
  }

  return 0;
}