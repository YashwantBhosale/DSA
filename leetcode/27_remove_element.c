int removeElement(int* nums, int numsSize, int val) {
    // Most embarrassing and desperate thing i have ever done.
    if(numsSize == 0)
        return 0;
    else if(numsSize == 1) {
        return nums[0] != val;
    }else if(numsSize == 2) {
        if(nums[0] == val && nums[1] == val) {
            return 0;
        }else if(nums[0] == val){
            nums[0] = nums[1];
            return 1;
        }else if(nums[1] == val){
            return 1;
        }else {
            return 2;
        }
    }

    int i = 0, j = numsSize-1;

    while(i < j) {
          if(nums[i] == val && nums[j] != val) {
            nums[i++] = nums[j];
            nums[j--] = val;
            continue;
        }
        
        if(nums[i] != val) {
            i++;
        }
        if(nums[j] == val) {
            j--;
        }
    }

    while(i < numsSize && nums[i] != val){
        i++;
    }

    return i;
}