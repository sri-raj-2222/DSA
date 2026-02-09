class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        map<int,int> mpp;
        for(int i : nums) mpp[i]++;
        for(int i=0;i<n;i++){
            if(mpp[nums[i]]){
                for(int j=1;j<k;j++){
                    if(mpp[nums[i]+j]){
                        mpp[nums[i]+j]--;
                    }
                    else return false;
                }
                mpp[nums[i]]--;
            }
        }
        return true;
    }
};