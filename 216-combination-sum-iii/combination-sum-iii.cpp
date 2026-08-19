class Solution {
public:
vector<vector<int>> ans;
    void solve(int k,int tar,vector<int> &arr,int i){
        if(tar == 0 && arr.size() == k){
            ans.push_back(arr);
            return;
        }
        if(tar < 0 || i > 9) return;
        arr.push_back(i);
        solve(k,tar-i,arr,i+1);
        arr.pop_back();
        solve(k,tar,arr,i+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        solve(k,n,arr,1);
        return ans;
    }
};