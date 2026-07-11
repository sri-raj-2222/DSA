class Solution {
public:
    void dfs(vector<int> & nums,vector<int> & arr,int i, int tar,vector<vector<int>> & ans){
        int n=nums.size();
        if(tar == 0){
            ans.push_back(arr);
            return;
        }
        if(tar < 0 || i == n) return;
        for(int j = i ; j < n ; j++){
            if(j > i && nums[j] == nums[j-1]) continue;
            arr.push_back(nums[j]);
            dfs(nums,arr,j+1,tar-nums[j],ans);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int tar) {
        vector<int> arr;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        dfs(nums,arr,0,tar,ans);
        return ans;   
    }
};