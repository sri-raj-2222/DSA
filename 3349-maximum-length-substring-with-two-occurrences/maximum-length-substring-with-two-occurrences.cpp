class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0,n=s.size(),maxi=0;
        unordered_map<char,int> mpp;
        for(int j=0;j<n;j++){
            mpp[s[j]]++;
            while(mpp[s[j]] > 2){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
            }
            maxi = max(maxi,j-i+1);
        }
        return maxi;
    }
};