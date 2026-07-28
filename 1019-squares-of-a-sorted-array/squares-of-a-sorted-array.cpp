class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        vector<int> ans(n);
        int ind=n-1;
        while(i <= j){
            int l = nums[i] * nums[i];
            int h = nums[j] * nums[j];
            if(l > h){
                ans[ind]=l;
                i++;
            }
            else{
                ans[ind] = h;
                j--;
            }
            ind--;
        }
        return ans;
    }
};