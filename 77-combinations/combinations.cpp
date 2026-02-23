class Solution {
public:
    void comb(int i,int n,int k,vector<int> &arr,vector<vector<int>> &nums){
        if(i > n+1) return;
        if(k == 0){
            nums.push_back(arr);
            return;
        }
        arr.push_back(i);
        comb(i+1,n,k-1,arr,nums);
        arr.pop_back();
        comb(i+1,n,k,arr,nums);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        vector<vector<int>> nums;
        comb(1,n,k,arr,nums);
        return nums;
    }
};