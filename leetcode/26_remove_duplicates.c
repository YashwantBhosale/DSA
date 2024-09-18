/* Remove duplicates from sorted array */
#include <stdio.h>

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}
/* 
 * 1, 1, 1, 2, 3, 4, 5, 5
   i  j

   1, 2, 1, 2, 3, 4, 5, 5
      i     j
   1, 2, 1, 2, 3, 4, 5, 5
      i        j
   1, 2, 3, 2, 3, 4, 5, 5
         i     j
   
   1, 2, 3, 2, 3, 4, 5, 5
         i        j
   1, 2, 3, 4, 3, 4, 5, 5
            i     j

   1, 2, 3, 4, 3, 4, 5, 5
            i        j
   1, 2, 3, 4, 5, 4, 5, 5
            i        j   
*/
int removeDuplicates(int *nums, int numsSize) {
    if(numsSize <= 1) 
        return numsSize;
    int len = 0, i = 0, j = 1;
    while(i < numsSize && j < numsSize) {
        while(j < numsSize && nums[i] == nums[j]) j++;
        nums[i+1] = nums[j];
        len++;
        i++;
    }
    if (nums[i] != nums[j])
        len++;
    return len;
}


/* same approach but more efficient solution O(n) */
int remove_duplicates(int *arr, int len) {
    if(len <= 1) 
        return 1;
    int new_len = 0, j = 1;
    while(new_len < len && j < len) {
        if(arr[new_len] == arr[j]) {
            j++;
        }
        else {
            arr[++new_len] = arr[j];
        }
    }
    return new_len+1;
}

void print(int *arr, int len) {
    for(int i = 0;i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return;
}

int main() {
    int arr[] = {1, 1, 1, 2, 3, 4, 5, 5};
    int len = sizeof(arr) / sizeof(len);
    
    len = remove_duplicates(arr, len);
    print(arr, len);
    printf("new len = %d\n", len);
    return 0;
}
