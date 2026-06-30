class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        map<char,int> mpp;
       int cnt=0;
        for(int i=0;i<n;i++){
            mpp[s[i]] = i;
            if(mpp.find('a') != mpp.end() && mpp.find('b') != mpp.end() && mpp.find('c') != mpp.end()){
                cnt += 1+min({mpp['a'],mpp['b'],mpp['c']});
            }
        }
        return cnt;
    }
};