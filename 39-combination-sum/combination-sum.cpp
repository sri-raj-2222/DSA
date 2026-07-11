class Solution {
public:
    void dfs(vector<int> & nums,vector<int> & arr,int i, int tar,vector<vector<int>> & ans){
        int n=nums.size();
        //base
        if(tar == 0){
            ans.push_back(arr);
            return;
        }
        if(tar < 0 || i == n) return;
        //logic
        arr.push_back(nums[i]);
        dfs(nums,arr,i,tar-nums[i],ans);
        arr.pop_back();
        dfs(nums,arr,i+1,tar,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int tar) {
        vector<int> arr;
        vector<vector<int>> ans;
        dfs(nums,arr,0,tar,ans);
        return ans;
    }
};