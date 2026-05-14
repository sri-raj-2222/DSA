class Solution {
public:
    bool isGood(vector<int>& nums) {
        if(nums.size() == 1) return false;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size()-2 ; i++){
            if(nums[i]+1 == nums[i+1] && nums[i] == i+1 && nums[i+1] == i+2) continue;
            else return false;
        }
        if(nums[nums.size()-2] == nums[nums.size()-1] && nums[nums.size()-1] == nums.size()-1) return true;
        else return false;
    }
};