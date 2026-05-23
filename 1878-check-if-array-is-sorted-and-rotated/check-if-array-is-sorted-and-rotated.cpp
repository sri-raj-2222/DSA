class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            nums.push_back(nums[i]);
        }
        int cnt = 1 , maxi = -1;
        n=nums.size();
        for(int i = 0 ; i < n-1 ; i++){
            if(nums[i] <= nums[i+1]) cnt++;
            else cnt = 1;
            maxi = max(maxi,cnt);
        }
        cout<<maxi;
        if(maxi == n/2 || maxi == n) return true;
        else return false;
    }
};