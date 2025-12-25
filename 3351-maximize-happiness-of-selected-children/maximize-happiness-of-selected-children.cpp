class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend());
        long long cnt=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] - cnt > 0){
                ans+=1LL*nums[i];
                ans-=cnt;
                cnt++;
                if(cnt==k) break;
            }
            else ans+=0;
        }
        
        return ans;
    }
};