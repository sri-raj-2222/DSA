class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int leftAns=-1,rightAns=-1;
        while(left <= right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                leftAns=mid;
                right=mid-1;
            }
            else if(target > nums[mid]) left=mid+1;
            else right=mid-1;
        }
        left=0;
        right=nums.size()-1;
        while(left <= right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                rightAns=mid;
                left=mid+1;
            }
            else if(target > nums[mid]) left=mid+1;
            else right=mid-1;
        }
        return{leftAns,rightAns};
    }
};