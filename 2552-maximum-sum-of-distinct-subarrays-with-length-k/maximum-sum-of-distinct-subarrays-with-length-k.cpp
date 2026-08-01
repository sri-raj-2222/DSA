class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        long long sum=0;
        for(int i=0;i<k;i++){
            sum += nums[i];
            mpp[nums[i]]++;
        }
        long long maxi = 0;
        if(mpp.size() == k) maxi=sum;
        for(int i=k;i<nums.size();i++){
            mpp[nums[i-k]]--;
            sum-=nums[i-k];
            if(mpp[nums[i-k]] == 0) mpp.erase(nums[i-k]);
            mpp[nums[i]]++;
            sum+=nums[i];
            if(mpp.size() == k) maxi = max(maxi,sum);
        }
        return maxi;
    }
};