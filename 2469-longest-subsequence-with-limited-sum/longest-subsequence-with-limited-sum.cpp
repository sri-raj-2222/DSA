class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> pre(n),arr;
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }
        for(int i=0;i<queries.size();i++){
            int val = queries[i];
            int l = 0;
            int r = n-1;
            int ans = 0;
            while(l <= r){
                int mid = (l+r)/2;
                if(pre[mid] <= val){
                    ans = mid+1;
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            arr.push_back(ans);
        }
        return arr;
    }
};