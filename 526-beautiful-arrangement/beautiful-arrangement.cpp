class Solution {
public:
int ans = 0;
void solve(vector<int> &nums,int n,vector<bool>&vis,vector<int>&arr,int j){
    if(arr.size() == n){
        ans++;
        return;
    }
    for(int i=0;i<n;i++){
        if(!vis[i] && (nums[i]%(j+1) == 0 || (j+1)%nums[i] == 0)){
            vis[i] = 1;
            arr.push_back(nums[i]);
            solve(nums,n,vis,arr,j+1);
            arr.pop_back();
            vis[i] = 0;
        }
    }
}
    int countArrangement(int n) {
        vector<int>nums(n,0);
        for(int i=0;i<n;i++) nums[i] = i+1;
        vector<bool> vis(n,0);
        vector<int> arr;
        solve(nums,n,vis,arr,0);

        return ans;
    }
};