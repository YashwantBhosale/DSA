#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct {
    int num;
    int index;
} node;
/*
 * Inefficient hash function unnecessary loops will only slow down the program
int hash(int num) {
    int prime = 1223;
    long hash = 0;
    while(num) {
        hash = hash * 19 + (num / 7) * (num % 3) + 107;
        num = num / 7;
    }
    return (int) (num*prime) % INT_MAX;
}
*/

/* Improved hash function spans range more efficiently */
int hash(int num) {
    long long hash = num; 
    long long prime = 31;
    hash = (hash * prime) % INT_MAX;
    hash = (hash ^ (hash >> 16)) % INT_MAX;
    hash = (hash * 0x85ebca6b) % INT_MAX;
    hash = (hash ^ (hash >> 13)) % INT_MAX;
    hash = (hash * 0xc2b2ae35) % INT_MAX;
    hash = (hash ^ (hash >> 16)) % INT_MAX;
    return (int)hash;
}

short int insert(node **hash_table, int element, int og_index, int index, int len) {
    node *nn = (node *) malloc(sizeof(node));
    nn -> num = element;
    nn -> index = og_index;
    if(hash_table[index] == NULL) {
        hash_table[index] = nn;
        return 1;
    }
    else if (hash_table[index] -> num == element) {
        return 0;
    }
    else {
        while(hash_table[index] != NULL) {
            index = (index+1) % len;
        }
        hash_table[index] = nn;
        return 1;
    }
}

int search(node **hash_table, int len, int element) {
    int index = hash(element) % len;
    if(hash_table[index] == NULL)
        return -1;
    if(hash_table[index] -> num == element) {
        return hash_table[index] -> index;
    }
    while(hash_table[index] != NULL) {
        if(hash_table[index] -> num == element) 
            return hash_table[index] -> index;
        index = (index+1)%len;
    }
    return -1;
}

void init(node **hash_table, int len) {
    for (int i = 0; i < len; i++) {
        hash_table[i] = NULL;
    }
    return;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    if(!nums)
        return NULL;
    node *hash_table[numsSize];
    init(hash_table, numsSize);
    for(int i = 0; i < numsSize; i++) {
        int index = hash(nums[i]) % numsSize;
        int key = target - nums[i];
        int key_index = search(hash_table, numsSize, key);
        if(key_index >= 0) {
            *returnSize = 2;
            int *result = (int *) malloc(sizeof(int) * 2);
            result[0] = key_index;
            result[1] = i;
            return result;
        }else {
            insert(hash_table, nums[i], i, index, numsSize);
        }
    }   
    *returnSize = 0;
    return NULL;
}

void print_array(int *arr, int len) {
    printf("[\t");
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("]\n");
    return;
}

int main() {
    int arr[] = {3,3};
    int len = sizeof(arr) / sizeof(int), target = 6;
    int *returnSize = (int *) malloc(sizeof(int));
    *returnSize = 2;
    int *result = twoSum(arr, len, target, returnSize);
    print_array(result, *returnSize);
    return 0;
}
