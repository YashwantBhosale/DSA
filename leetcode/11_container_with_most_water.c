#include <stdio.h>
#include <limits.h>

int area(int *heights, int i, int j) {
    int length = heights[i] <= heights[j] ? heights[i] : heights[j];
    int breadth = (j - i);
    return length * breadth;
}

int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize-1, max_area = INT_MIN;
    while(left < right) {
        int _area = area(height, left, right);
        if(_area > max_area) {
            max_area = _area;
        }
        /* Goal is to maximize the area function, so adjust pointers to get larger values of height */
        if(height[left] < height[right])
            left++;
        else
            right--;
    }
    return max_area;
}


int main() {
    int arr[] = {1,8,100,2,100,4,8,3,7};
    int len = sizeof(arr) / sizeof(int);
    printf("Max area = %d\n", maxArea(arr, len));
    return 0;
}
