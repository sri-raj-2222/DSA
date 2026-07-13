class Solution {
public:
vector<vector<int>> ans;
    void solve(vector<int> &nums,vector<int> &arr,vector<bool> &vis){
        if(arr.size() == nums.size()){
            ans.push_back(arr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                arr.push_back(nums[i]);
                vis[i] = 1;
                solve(nums,arr,vis);
                arr.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr;
        vector<bool> vis(n);
        solve(nums,arr,vis);
        return ans;
    }
};