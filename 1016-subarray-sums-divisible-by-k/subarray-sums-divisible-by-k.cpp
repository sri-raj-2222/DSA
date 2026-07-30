class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1]+nums[i];
        }
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int ans = 0;
        for(int i=0;i<n;i++){
            int val = ((pre[i] % k) + k) % k;
            if(mpp[val] > 0){
                ans += mpp[val];
            }
            mpp[val]++;
        }
        return ans;
    }
};