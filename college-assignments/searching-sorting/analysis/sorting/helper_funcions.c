#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "helper_functions.h"


int *read_array_from_csv(const char *filename, int len) {
    int *arr = (int *)calloc(len, sizeof(int));
    if (arr == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error: Unable to open file\n");
        free(arr);
        return NULL;
    }

    char buffer[1]; 
    int index = 0, current_number = 0;
    int is_number_in_progress = 0;

    while (read(fd, buffer, 1) > 0) {
        if (buffer[0] >= '0' && buffer[0] <= '9') {
            current_number = current_number * 10 + (buffer[0] - '0');
            is_number_in_progress = 1;
        } else if (buffer[0] == ',' || buffer[0] == '\n') {
            // If delimiter is reached, save the number and reset
            if (is_number_in_progress) {
                if (index < len) {
                    arr[index++] = current_number;
                }
                current_number = 0;
                is_number_in_progress = 0;
            }
        }
    }

    // Handle the last number if the file doesn't end with a delimiter
    if (is_number_in_progress && index < len) {
        arr[index++] = current_number;
    }

    close(fd);

    // Verify if we read the expected number of elements
    if (index != len) {
        printf("Warning: Expected %d elements, but found %d\n", len, index);
    }

    return arr;
}

void read_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
