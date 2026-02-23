class Solution {
public:
    void dfs(int a,vector<int> &nums,set<vector<int>> & arr){
        if(a > 1+nums.size()) return;
        arr.insert(nums);
        for(int i=1;i<nums.size();i++){
            swap(nums[0],nums[i]);
            dfs(a+1,nums,arr);
            swap(nums[0],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> arr;
        dfs(0,nums,arr);
        for(auto i : arr){
            ans.push_back(i);
        }
        return ans;
    }
};