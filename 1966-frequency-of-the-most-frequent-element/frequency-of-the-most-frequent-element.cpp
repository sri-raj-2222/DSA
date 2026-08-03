class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size(),maxi = 1,j=0;
        sort(nums.begin(),nums.end());
        long long sum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if((long long)nums[i] * (i-j+1) - sum > k){
                sum -= nums[j++];
            }
            maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
};