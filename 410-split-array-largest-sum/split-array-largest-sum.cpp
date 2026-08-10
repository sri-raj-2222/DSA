class Solution {
public:
    bool check(vector<int> & nums,int tar,int k){
        int sum = 0,n=nums.size(),cnt=1,maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(sum + nums[i] > tar){
                sum = nums[i];
                maxi = max(maxi , sum);
                cnt++;
            }
            else sum += nums[i];
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int high = 0,low = *max_element(nums.begin(),nums.end()),ans = INT_MAX;
        for(int i : nums) high += i;
        while(low <= high){
            int mid = (low+high)/2;
            bool a = check(nums,mid,k);
            if(a){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};