class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mpp;
        int i=0,j=0,maxi=0,n=s.size();
        while(i<=j && j<n){
            mpp[s[j]]++;
            if(mpp[s[j]] > 1){
                while(mpp[s[j]] > 1){
                    mpp[s[i]]--;
                    i++;
                }
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};