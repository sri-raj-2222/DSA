class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i : nums) mpp[i]++;
        int sum = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]+1) sum += nums[i];
            else break;
        }
        cout<<sum;
        while(1){
            if(mpp[sum] > 0){
                sum++;
            }
            else return sum;
        }
        return -1;
    }
};