class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> arr;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=1; j<(nums[i+1]-nums[i]);j++){
                int a=nums[i]+j;
                arr.push_back(a);
            }
        }
        return arr;
    }
};