class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,a=0;
        int maxi=0,k=1;
        while(i <= j && j < n){
            if(nums[j] == 0) a++;
            while(a > k){
                if(nums[i] == 0){
                    a--;
                }
                i++;
            }
            maxi = max(maxi,j-i);
            j++;
        }
        return maxi;
    }
};