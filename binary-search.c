#include <stdio.h>

int binary_search(int *nums, int numsSize, int target){
	int right = numsSize - 1;
	int left = 0;
	int mid;

	for (int i = 0; i < numsSize; i++){
		mid = (left + right) / 2;
		if(target == nums[mid])
			return mid;
		else if(target < nums[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
	
}

int main(){

	return 0;
}
