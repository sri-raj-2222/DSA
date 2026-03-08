class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return -1;
        vector<long long> pre(n),suf(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(suf[i+1] >= LLONG_MAX/nums[i]) suf[i]=LLONG_MAX;
            else suf[i]=suf[i+1]*nums[i];;
        }
        if(suf[1] == 0) return 0;
        else if(pre[n-2]==1) return n-1;
        else{
            for(int i=1;i<n-1;i++){
                if(pre[i-1]==suf[i+1]) return i;
            }
        }
        return -1;
    }
};