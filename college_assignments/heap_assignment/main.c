#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "heap.h"

void print_array(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(int argc, char **argv) {
	Heap h1;
	char str[100], *token;
	int arr[100];

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("Failed to open file\n");
		return 1;
	}

	int bytes = read(fd, str, sizeof(char) * 100);
	if (bytes == -1) {
		perror("Failed to read file\n");
		return 1;
	}

	token = strtok(str, ",");
	int i = 0;
	while (token != NULL) {
		arr[i++] = atoi(token);
		token = strtok(NULL, ",");
	}

	print_array(arr, i);
	init_heap(&h1, i);

    for (int j = 0; j < i; j++) {
        insert_heap(&h1, arr[j]);
    }
	printf("After performing heap sort\n");
	heap_sort(&h1);
	print_heap(&h1);

	return 0;
}
