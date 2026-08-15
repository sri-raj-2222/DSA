class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        long long sum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) cnt++;
            sum^=(1LL)*nums[i];
        }
        if(sum==0 && cnt==0) return nums.size()-1;
        else if(sum==0 && cnt==nums.size()) return 0;
        else if(sum==0 && cnt > 0) return nums.size()-1;
        else return nums.size();
    }
};