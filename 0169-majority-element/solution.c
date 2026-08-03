int majorityElement(int* nums, int numsSize) {
    int i,j,  freq=1, a= nums[0] ;
    for(i = 1; i < numsSize; i++ ){
      if(nums[i] == a){
        freq++;
      }
       else{
        freq--;
        if(freq==0)
        {
            a = nums[i];
            freq =1;
        }
       }
    }
    return a;
}
