class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mpp;
        int ans = 0,cnt = 0;
        for(auto ch : word){
            mpp[ch]++;
        }
        vector<int> nums;
        for(auto i : mpp){
            nums.push_back(i.second);
        }
        sort(nums.rbegin(),nums.rend());
        for(int i : nums){
            ans += ((cnt/8)+1)*i;
            cnt++;
        }
        return ans;
    }
};