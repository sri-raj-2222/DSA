class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        int maxi=nums[0];
        long long sum=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            pre[i] = gcd(nums[i],maxi);
        }
        sort(pre.begin(),pre.end());
        for(int i=0;i<n/2;i++){
            sum += 1LL * gcd(pre[i],pre[n-i-1]);
        }
        return sum;
    }
};