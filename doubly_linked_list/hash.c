#include <limits.h>

void init_ht(int *ht, int len) {
    for (int i = 0; i < len; i++) {
        ht[i] = INT_MIN;
    }
    return;
}

int hash(int key, int len) {
    int hash = key * 31; // Multiply by a prime number
    return hash % len;
}

short int insert(int *arr, int element, int index, int len) {
    if(arr[index] == INT_MIN) {
        arr[index] = element;
    }
    else {
        if(arr[index] == element)
            return 0;
        while(arr[index] != INT_MIN) {
            if(arr[index] == element)
                return 0;
            index = (index+1) % len;
        }
        arr[index] = element;
    }   
    return 1;
}
