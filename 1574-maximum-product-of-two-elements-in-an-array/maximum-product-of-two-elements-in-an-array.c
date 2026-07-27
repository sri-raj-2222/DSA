int maxProduct(int* nums, int n) {
    int max1=nums[0],i1=0;
    for(int i=0;i<n;i++){
        if(nums[i]>max1) max1=nums[i],i1=i;
    }
    nums[i1]=0;
    int max2=nums[0];
    for(int i=0;i<n;i++){
        if(nums[i]>max2) max2=nums[i];
    }
    return (max1-1)*(max2-1);
}