#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
ref: https://algorithms-digest.medium.com/jump-game-e68298e2d809

recursive function : is_reachable( ... )
1. is_reachable(int *nums, int i, int len); -> will calculate if we can reach the end from index i
2. base case will be when we will be at last index itself.
*/

/*
Solution 1: Less optimal but elegant

bool is_reachable(int *nums, int i, int len) {
    // base case
    if(i == len-1) {
        return true;
    }

    int count = nums[i];
    while(count && (i+count) < len) {
        if(is_reachable(nums, i+count, len))
            return true;
        count--;
    }
    return false;
}

bool canJump(int* nums, int numsSize) {
    bool canjump = is_reachable(nums, 0, numsSize);
    return canjump;
}

*/

/*
!! !! !!
Solution 2: 0(n) : Dynamic Programming

Most important thing in this problem is to find CORRECT smaller problem. What i mean is there are
primararily two small problems one that we solved using recursion and another is where we use DP.

So the important part is not reaching end from current position, But reaching a position from which
we can reach the end. This is so important and hard to see. It makes the time complexity O(n).

It works like this we need to keep track of the positions from which we can reach the end.
How?

1.  we will start from the end (last index) and go all the way to 0th index.
2.  at each step we will try to reach end. But differently this time. 
    We will keep track of a variable which denotes the MINIMUM INDEX from which we reach the end.
    it will be initialized to n-1 which is the end and we will update it when we are iterating over
    the list.
    at each step we will try to reach this MINIMUM INDEX instead of trying to reach the end.
    ** THIS IS THE MOST BRILLIANT THING ABOUT THIS APPROACH ** It avoids the unnecessary redundant
    checks.
    ref: https://miro.medium.com/v2/resize:fit:720/format:webp/1*1JWttHszXqsRlObz7Fdxtw.png
    this image shows precisely how we are doing redundant checks.
*/
bool canJump(int *nums, int numsSize) {
	int min_reachable = numsSize - 1;
	for (int i = numsSize - 2; i >= 0; i--)
		if (i + nums[i] >= min_reachable)
			min_reachable = i;
	return min_reachable == 0;
}

int main() {
	int nums[] = {3, 2, 1, 0, 4};
	int len = sizeof(nums) / sizeof(int);

	printf("Can Jump? -> %s\n", canJump(nums, len) ? "True" : "False");
	return 0;
}