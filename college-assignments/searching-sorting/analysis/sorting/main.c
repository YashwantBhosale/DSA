#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>
#include <time.h>
#include <string.h>
#include "helper_functions.h"
#include "heap.h"

// 1. Bubble Sort
void bubble_sort(int *arr, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - (i + 1); j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr, j, j + 1);
			}
		}
	}
}

// 2. Bubble sort V2
/*
    there is one obvious optimization that we can do in
    the bubble sort algorithm. If in any iteration, we do not
    swap any elements, then the array is already sorted.
    So, we can break out of the loop and return.
*/
void bubble_sort_v2(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        int swapped = 0; // Flag to track if any swaps happened in this pass
        for (int j = 0; j < len - (i + 1); j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
                swapped = 1; // Mark as swapped
            }
        }
        if (!swapped) {
            break; // Array is sorted, exit early
        }
    }
}


// 3. Insertion Sort (swapping)
void insertion_sort_swapping(int *arr, int len) {
    for(int i=1; i<len; i++) {
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]) {
            swap(arr, j, j-1);
            j--;
        }
    }
    return;
}

// 4. Insertion Sort (Shifting)
void insert(int key, int arr[], int j) {
    // insert key into the sorted subarray arr[0] to arr[j-1]
    // by shifting elements to the right until the correct position is found

    while (j >= 0 && arr[j] > key) {
        arr[j+1] = arr[j];
        j = j-1;
    }
    arr[j+1] = key;
}

void insertion_sort(int arr[], int n) {
    // sort a[0] to a[n-1] into nondecreasing order

    for (int i = 1; i < n; i++) {
        // insert a[i] into the sorted subarray a[0] to a[i-1]
        int key = arr[i];
        int j = i-1;
        insert(key, arr, j);
    }
}

// 5. Selection Sort
void selection_sort(int *arr, int len) {
    for (int i=0; i < len; i++){
        
        int min_index = i; // Index of the minimum element

        for (int j = i+1; j < len; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        swap(arr, i, min_index);
    }
    return;
}

// 6. Quick Sort
void quick_sort(int *arr, int left, int right) {
	// base case
	if (left >= right) {
		return;
	}

	int pivot = arr[(left + right) / 2];  // pick the middle element as pivot
	int i = left, j = right;

	/*
	    quick sort works by partitioning the array into two subarrays
	    such that all elements in the left subarray are less than the pivot
	    and all elements in the right subarray are greater than the pivot
	*/

	while (i <= j) {
		// find the first element from the left that is greater than the pivot
		while (arr[i] < pivot) {
			i++;
		}

		// find the first element from the right that is less than the pivot
		while (arr[j] > pivot) {
			j--;
		}

		// swap the elements at i and j
		if (i <= j) {
			swap(arr, i, j);
			i++;
			j--;
		}
	}

	// recursively sort the left and right subarrays
	quick_sort(arr, left, j);
	quick_sort(arr, i, right);
	return;
}

// 7. Heap Sort
void heap_sort(int *arr, int len) {
    Heap heap;
    init_heap(&heap, len);
    free(heap.h);

    heap.h = arr;
    heap.size = len;
    heap.rear = len-1;

    build_max_heap(&heap);
    int old_rear = heap.rear;

    for(int i = heap.rear; i >= 0; i--) {
        swap_heap(&heap, 0, i);
        heap.rear--;
        heapify(&heap, 0);
    }

    heap.rear = old_rear;
    return;
}

int main(int argc, char *argv[]) {
    int len = argc > 1 ? atoi(argv[1]) : 1000;
    int *arr_original = read_array_from_csv(argv[2], len);
    if (arr_original == NULL) {
        return 1;
    }

    int *arr = (int *)malloc(len * sizeof(int));
    if (arr == NULL) {
        printf("Error: Memory allocation failed\n");
        free(arr_original);
        return 1;
    }

    printf("Sorting %d elements\n", len);

    clock_t start, end;
    double time_ms;

    // Bubble Sort
    printf("1. Bubble Sort\n");
    memcpy(arr, arr_original, len * sizeof(int));
    start = clock();
    bubble_sort(arr, len);
    end = clock();
    time_ms = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
    printf("time taken to sort %d elements = %.5lfms\n\n", len, time_ms);

    
    printf("2. Bubble Sort V2\n");
    memcpy(arr, arr_original, len * sizeof(int));
    start = clock();
    bubble_sort_v2(arr, len);
    end = clock();
    time_ms = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
    printf("time taken to sort %d elements = %.5lfms\n\n", len, time_ms);

    // Insertion Sort (Swapping)
    printf("3. Insertion Sort (Swapping)\n");
    memcpy(arr, arr_original, len * sizeof(int));
    start = clock();
    insertion_sort_swapping(arr, len);
    end = clock();
    time_ms = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
    printf("time taken to sort %d elements = %.5lfms\n\n", len, time_ms);

    // Insertion Sort (Shifting)
    printf("4. Insertion Sort (Shifting)\n");
    memcpy(arr, arr_original, len * sizeof(int));
    start = clock();
    insertion_sort(arr, len);
    end = clock();
    time_ms = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
    printf("time taken to sort %d elements = %.5lfms\n\n", len, time_ms);

    // Selection Sort
    printf("5. Selection Sort\n");
    memcpy(arr, arr_original, len * sizeof(int));
    start = clock();
    selection_sort(arr, len);
    end = clock();
    time_ms = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
    printf("time taken to sort %d elements = %.5lfms\n\n", len, time_ms);

    // Quick Sort
    printf("6. Quick Sort\n");
    memcpy(arr, arr_original, len * sizeof(int));
    start = clock();
    quick_sort(arr, 0, len - 1);
    end = clock();
    time_ms = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
    printf("time taken to sort %d elements = %.5lfms\n\n", len, time_ms);

    // Heap Sort
    printf("7. Heap Sort\n");
    memcpy(arr, arr_original, len * sizeof(int));
    start = clock();
    heap_sort(arr, len);
    end = clock();
    time_ms = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
    printf("time taken to sort %d elements = %.5lfms\n\n", len, time_ms);
    
    free(arr_original);
    free(arr);
    return 0;
}
