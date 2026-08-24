int maxArea(int* nums, int n) {
    int i=0,j=n-1;
    int k=n-1,m=0;
    int *arr=(int*)calloc(k,sizeof(int));
    while(k>=1){
        int ans1=nums[i]*k;
        int ans2=nums[j]*k;
        int ans=(ans1<ans2)?ans1:ans2;
        if(ans2>ans1) i++;
        else j--;
        arr[m]=ans;
        k--,m++;
    }
    int max=arr[0];
    for(int i=0;i<n-1;i++){
        if(arr[i]>max) max=arr[i];
    }
    for(int i=0;i<n-1;i++) printf("%d ",arr[i]);
    return max;
}