class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return {};
        vector<pair<int,int>> nums;
        for(int i=0;i<n;i++){
            nums.push_back({arr[i],i});
        }
        sort(nums.begin(),nums.end());
        int cnt=1;
        arr[nums[0].second] = cnt;
        for(int i=1;i<n;i++){
            if(nums[i-1].first != nums[i].first){
                cnt++;
            }
            arr[nums[i].second] = cnt;
        }
        return arr;
    }
};