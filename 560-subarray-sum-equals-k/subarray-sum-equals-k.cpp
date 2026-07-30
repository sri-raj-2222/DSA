class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1 && nums[0] == k) return 1;
        else if(n==1) return 0;
        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1]+nums[i];
        }
        map<int,int> mpp;
        mpp[0] = 1;
        int ans = 0;
        for(int i=0;i<n;i++){
            int val = pre[i] - k;
            if(mpp[val] > 0){
                ans += mpp[val];
            }
            mpp[pre[i]]++;
        }
        return ans;
    }
};