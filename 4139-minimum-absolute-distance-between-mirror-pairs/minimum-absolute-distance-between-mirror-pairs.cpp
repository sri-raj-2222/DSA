class Solution {
public:
    int reverse(int x){
        int rev = 0;
        while(x){
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        map<int,int> mpp;
        int ans = INT_MAX;
        for(int i = 0 ; i < nums.size() ; i++){
            if(mpp.count(nums[i])){
                ans = min (ans , abs(i - mpp[nums[i]]));
            }
            mpp[reverse(nums[i])] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};