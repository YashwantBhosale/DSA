#include <stdio.h>

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void print(int arr[], int len);

int partition(int arr[], int start, int end)
{
    int key = end;
    swap(arr, key, start);
    int i = start + 1, j = end;
    while (i <= j)
    {
        while (arr[i] < arr[0])
        {
            i++;
        }

        while (arr[j] > arr[0])
        {
            j--;
        }

        if (i > j)
            break;

        swap(arr, i, j);
    }
    swap(arr, j, 0);
    printf("\nThis is a partition call : ");
    print(arr, 10);
    return j;
}

void quicksort(int arr[], int left, int right)
{
    if(left >= right)
        return;
     //2
    printf("left: %d, right: %d\n", left, right);
    // swap(arr, mid, 0);
    // left = left + 1;
    int pivot = partition(arr, left, right);
    printf("pivot after partition : %d \n", pivot);
    printf("\n\nthis is a quicksort call : ");


    print(arr, 10);
    quicksort(arr, left, pivot - 1);
    int pivot2 = partition(arr, 2, 9);
    printf("pivot2 : %d\n", pivot2);
    print(arr, 10);
   // quicksort(arr, pivot+1, right);
}

void print(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {28, 26, 25, 11, 16, 12, 24, 29, 6, 10};
    printf("original array : ");
    print(arr, 10);

//    int pivot = partition(arr, 0, 9);
    quicksort(arr, 0, 9);
    printf("\narray after partition : ");
//    printf("pivot : %d\n", pivot);
    print(arr, 10);
    return 0;
}
