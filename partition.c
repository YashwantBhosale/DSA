#include <stdio.h>

void swap(int arr[], int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void print(int arr[], int len);

void partition(int arr[], int len, int key)
{
  swap(arr, key, 0);
  int i = 1, j = len - 1;
  printf("array after isolating (key)th element to 0th position : ");
  print(arr, len);
  while (i <= j)
  {
    printf("looping..\n");
    while (arr[i] < arr[0])
    {
      i++;
    }
    printf("element to be swapped from left side where i is %d = %d\n", i, arr[i]);

    while (arr[j] > arr[0])
    {
      j--;
    }
    printf("element to be swapped from right side where j is %d = %d\n", j, arr[j]);

    if (i > j)
      break;

    swap(arr, i, j);
  }
  swap(arr, j, 0);
}

void print(int arr[], int len)
{
  for (int i = 0; i < len; i++)
    printf("%d\t", arr[i]);
}

int main()
{
  int arr[] = {1, 4, 8, 0, 3, 5};
  printf("original array : ");
  print(arr, 6);

  partition(arr, 6, 2);

  printf("\narray after partition : ");
  print(arr, 6);

  return 0;
}
