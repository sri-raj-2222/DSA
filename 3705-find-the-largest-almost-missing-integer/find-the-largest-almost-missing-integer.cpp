class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,int> mpp;
        int n = nums.size();
        for(int i=0;i<=n-k;i++){
            set<int> st;
            for(int j=i;j<i+k;j++){
                st.insert(nums[j]);
            }
            for(auto &i : st) mpp[i]++;
        }
        for(auto i : mpp){
            cout<<i.first<<" "<<i.second<<"\n";
        }
        int mini = INT_MAX,ans = -1,f = 0;
        for(auto i : mpp){
            if(i.second == 1){
                f = 1;
                ans = max(ans,i.first);
            }
        }
        if(f == 0) return -1;
        else return ans;
    }
};