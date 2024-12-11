#include <stdio.h>

void print(int *arr, int len) {
    for(int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return;
}
void remove_element(int *arr, int len, int index) {
    for (int i = index; i < len-1; i++) {
        arr[i] = arr[i+1];
    }
    return;
}
int remove_duplicates(int *arr, int len) {
    for(int i = 0; i < len; i++) {
        for(int j = i; j < len; j++) {
            if(arr[i] == arr[j]){
                remove_element(arr, len, j);
                len--;
            }
        }
    }
    return len;
}
int main() {
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    print(arr, 10);
    int len = remove_duplicates(arr, 10);
    print(arr, len);
    return 0;
}