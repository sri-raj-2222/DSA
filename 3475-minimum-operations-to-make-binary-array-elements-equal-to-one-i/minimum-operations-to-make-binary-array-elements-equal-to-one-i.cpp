class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==0){
                for(int j=i;j<i+3;j++){
                    if(nums[j]==1) nums[j]=0;
                    else nums[j]=1;
                }
                cnt++;
            }
        }
        if(find(nums.begin(),nums.end(),0) !=  nums.end()) return -1;
        else return cnt;
    }
};