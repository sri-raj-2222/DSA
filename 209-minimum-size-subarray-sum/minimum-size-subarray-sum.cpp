class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int cur_sum=0;
        int size=INT_MAX;
        while(j<nums.size() && i <= j){
            if(cur_sum >= target ){
                size=min(size,j-i);
                cur_sum -= nums[i++];
            }
            else{
                cur_sum += nums[j++];
                if(cur_sum >= target) size=min(size,j-i); 
            }
        }
        cur_sum -= nums[i++];
        while(cur_sum >= target){
            size = min(size,j-i);
            cur_sum -= nums[i++];
        }
        if(size==INT_MAX) return 0;
        else return size;
    }
};