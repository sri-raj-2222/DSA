class Solution {
public:
    bool check(int mid,vector<int> & nums,int h){
        long long sum = 0;
        int n = nums.size();
        for(int i = 0; i < n ; i++){
            int val = nums[i]/mid;
            sum +=  val;
            if(nums[i]%mid != 0) sum++;
        }
        return sum <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1, high = 0;
        for(int i : piles) high += i;
        int ans = 0;
        while(low <= high){
            long long mid = (low+high)/2;
            if(check(mid,piles,h)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};