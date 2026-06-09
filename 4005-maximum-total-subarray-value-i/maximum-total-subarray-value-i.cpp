class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ma=*max_element(nums.begin(),nums.end());
        long long mi=*min_element(nums.begin(),nums.end());
        return (ma-mi)*(1LL*k);
    }
};