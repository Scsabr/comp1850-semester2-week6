#include <stdio.h>

void bubbleSort(int array[], int n);

int main(void) {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Before sorting: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  bubbleSort(arr, n);

  printf("After sorting: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

/**
 * @brief Sorts an array of integers in ascending order using the bubble sort algorithm.
 * 
 * @param arr The array of integers to be sorted.
 * @param n The number of elements in the array.
 */
void bubbleSort(int array[], int n) {
  
  int swapped = 0;
  int temp;
  
  for (int i=0; i<n; i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if (array[i]>array[j])
      {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
          swapped = 1;
      }
    }
    if (!swapped)
      break;
  }
}