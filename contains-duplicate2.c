#include <stdio.h>
#include <stdbool.h>

int entries[1024];
int len = 0;

bool isDuplicate(int key){
  for(int i = 0; i < len; i++){
    if(entries[i] == key)
      return true;
  }
  entries[len] = key;
  len++;
  return false;
}

bool containsDuplicate(int *nums, int numsSize){
  if(numsSize == 1)
    return false;

  for(int i = 0; i < numsSize; i++){
    if(isDuplicate(nums[i]))
      return true;
  }
  return false;

}

int hash(int num){
  
}
/*
int entries[1024];
int len = 0;

bool isDuplicate(int key){
  for(int i = 0; i < len; i++){
    if(entries[i] == key)
      return true;
  }
  entries[len] = key;
  len++;
  return false;
}

bool containsDuplicate(int arr[], int len){
  for(int i = 0; i < len; i++){
    if(isDuplicate(arr[i]))
      return true;
  }
  return false;
}
*/
int main(){
  int arr[6];
  int length = 0;
  while(scanf("%d", &arr[length++]) != EOF)
    ;
  length--;
  if(containsDuplicate(arr, length)){
    printf("true\n");
  }
  else
    printf("false\n");
  return 0;
}
