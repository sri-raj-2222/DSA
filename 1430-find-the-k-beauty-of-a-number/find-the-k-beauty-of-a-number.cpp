class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str=to_string(num);
        string s="";
        int ans=0,val1=0;

        for(int i=0;i<k;i++){
            s+=str[i];
            val1 = stoi(s);
        }
        if(num % val1 == 0) ans++;
        for(int i=k;i<str.size();i++){
            s+=str[i];
            string sub = s.substr(i-k+1,k);
            int val = stoi(sub);
            cout<<val<<" ";
            if(val!=0 && num % val == 0) ans++;
        }
        return ans;
    }
};