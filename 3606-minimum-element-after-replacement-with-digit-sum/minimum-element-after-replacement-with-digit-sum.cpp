class Solution {
public:
    int minElement(vector<int>& nums) {
        int sum=0,ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum=0;
            while(nums[i]){
                sum+=nums[i]%10;
                nums[i]/=10;
            }
            if(sum<ans) ans=sum;
        }
        return ans;
    }
};