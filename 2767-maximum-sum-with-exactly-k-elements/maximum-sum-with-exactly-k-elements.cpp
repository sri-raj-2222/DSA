class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        return (k*(k-1))/2 + k*(*max_element(nums.begin(),nums.end()));
    }
};