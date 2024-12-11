// 15. Write code to find second max element in a 1D Array
#include <stdio.h>

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, max = 0, second_max = 0;
    for(int i = 0; i < 10; i++) {
        if(arr[i] > max) {
            second_max = max;
            max = arr[i];
        } else if(arr[i] > second_max) {
            second_max = arr[i];
        }
    }
    printf("Second max element: %d\n", second_max);
    return 0;
}