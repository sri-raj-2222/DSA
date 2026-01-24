class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int cur_sum=0;
        int size=INT_MAX;
        while(j<nums.size()){
            cur_sum+=nums[j++];
            while(cur_sum >= target){
                size=min(size,j-i);
                cur_sum-=nums[i++];
            }
            cout<<cur_sum<<" ";
        }
        if(size==INT_MAX) return 0;
        else return size;
    }
};