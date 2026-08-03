int compare(const void *a, const void *b){
    return(*(int *)a-*(int*)b);
}

int minPairSum(int* nums, int numsSize){
    int temp ,max = 0;
   /* for(int i = 0; i<numsSize; i++){
        for(int j = i + 1; j<numsSize; j++){
            if(nums[i]>nums[j]){
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] =temp;
            }
        }
    } */
qsort(nums, numsSize, sizeof(int), compare);
  int i = 0, j = numsSize - 1;
    while(i<j){
        int s = nums[i] + nums[j];
        if(s>max){
            max = s;
        } 
        i++;
        j--;
    }
return max;
}
