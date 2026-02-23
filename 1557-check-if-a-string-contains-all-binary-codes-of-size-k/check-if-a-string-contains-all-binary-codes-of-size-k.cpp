class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k)  return 0;
        map<string,int> mpp;
        int start=0;
        string str="";
        int n=s.size();
        for(int i=0;i<k;i++){
            str+=s[i];
        }
        mpp[str]++;
        for(int i=k;i<n;i++){
            str.erase(0,1);
            str+=s[i];
            mpp[str]++;
        }

        return mpp.size() == pow(2,k);
    }
};