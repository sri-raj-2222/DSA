class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for(auto arr : grid){
            for(int i : arr){
                nums.push_back(i);
            }
        }
        sort(nums.begin(),nums.end());
        int mid=nums[nums.size()/2];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(abs(mid-nums[i])%x==0){
                ans+=abs(mid-nums[i])/x;
            }else{
                return -1;
            }
        }
        return ans;
    }
};