class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        unordered_map<int,int> mpp;
        mpp[0] = 0;
        for(int i=1;i<n;i++){
            if(nums[i] - nums[i-1] <= maxDiff){
                mpp[i] = mpp[i-1];
            }
            else mpp[i] = i;
        }
        vector<bool> ans;
        for(auto &arr : queries){
            int l=arr[0];
            int r=arr[1];
            if(mpp[l] == mpp[r]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};