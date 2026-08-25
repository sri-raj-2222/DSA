class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int,int> mpp;
        for(int i: nums) mpp[i]++;
        int i=k;
        while(mpp.size()){
            if(i%k==0 && mpp[i]==0){
                return i;
            }
            else i+=k;
        }
        return i;
    }
};