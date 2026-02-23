class Solution {
public:
    long long fact(long long n){
        if(n==0 || n==1) return 1;
        else return n*fact(n-1);
    }
    void dfs(long long a,vector<int> &nums,set<vector<int>> & arr){
        if(arr.count(nums)) return;
        arr.insert(nums);
        for(int i=1;i<nums.size();i++){
            swap(nums[0],nums[i]);
            dfs(a,nums,arr);
            swap(nums[0],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> arr;
        long long a=fact(nums.size());
        dfs(a,nums,arr);
        for(auto i : arr){
            ans.push_back(i);
        }
        return ans;
    }
};