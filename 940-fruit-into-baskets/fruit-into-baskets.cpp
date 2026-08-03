class Solution {
public:
    int totalFruit(vector<int>& nums){
        int n = nums.size();
        map<int,int> mpp;
        int i=0,j=0,ans=0;
        while(i <= j && j < n){
            mpp[nums[j]]++;
            while(mpp.size() > 2){
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};