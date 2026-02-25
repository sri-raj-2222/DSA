class Solution {
public:
    int count(int n){
        int cnt=0;
        while(n > 0){
            cnt += (n&1);
            n>>=1;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> nums;
        for(int i : arr){
            nums.push_back({count(i),i});
        }
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(auto i : nums){
            ans.push_back(i.second);
        }
        return ans;
    }
};