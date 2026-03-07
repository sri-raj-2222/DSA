class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        map<int,int> mpp;
        for(auto i : arr) mpp[i]++;
        vector<pair<int,int>> nums;
        for(auto i : mpp){
            nums.push_back({i.second,i.first});
        }
        sort(nums.begin(),nums.end());
        for(auto &[i,j] : nums){
            if(i <= k && k>0){
                k-=i;
                i=0;
            }
        }
        int cnt=0;
        for(auto i : nums){
            if(i.first > 0){
                cnt++;
            }
        }
        return cnt;
    }
};