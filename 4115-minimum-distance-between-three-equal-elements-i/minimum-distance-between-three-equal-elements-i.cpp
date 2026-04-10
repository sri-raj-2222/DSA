class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        if(nums.size() <= 2) return -1;
        vector<pair<int,int>> arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        int maxi=INT_MAX;
        for(int i=0;i<arr.size()-2;i++){
            int ans=0;
            if(arr[i].first == arr[i+1].first && arr[i+1].first==arr[i+2].first){
                int a=arr[i].second,b=arr[i+1].second,c=arr[i+2].second;
                ans+=abs(a-b)+abs(b-c)+abs(c-a);
            }
            if(ans > 0) maxi=min(maxi,ans);
        }
        if(maxi==INT_MAX) return -1;
        return maxi;
    }
};