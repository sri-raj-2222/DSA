class Solution {
public:
    bool check(int mid, int days,vector<int>& nums){
        int n = nums.size();
        int sum = 0,cnt = 1;
        for(int i : nums){
            if(sum + i > mid){
                sum = i;
                cnt++;
            }
            else sum += i;
        }
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end()),high = 0,ans = 0;
        for(int i : weights) high += i;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(mid,days,weights)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};