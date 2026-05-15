class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        int a=INT_MAX;
        while(left <= right){
            int mid=(left+right)/2;
            a=min(a,nums[mid]);
            if(nums[mid] > nums[right]) left=mid+1;
            else right=mid-1;
        }
        return a;
    }
};