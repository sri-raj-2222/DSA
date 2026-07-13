class Solution {
public:
    void check(int i,string s,string str,vector<string> &ans){
        if(str.size() == s.size()){
            ans.push_back(str);
            return;
        }
        if(i == s.size()) return;
        if(s[i] >= '0' && s[i] <= '9'){
            str+=s[i];
            check(i+1,s,str,ans);
            str.pop_back();
        }
        else{
            char a = s[i];
            check(i+1,s,str+=a,ans);
            str.pop_back();
            if(s[i] >= 'a' && s[i] <= 'z'){
                a = toupper(a);
                str += a;
                check(i+1,s,str,ans);
            }
            else{
                a = tolower(a);
                str += a;
                check(i+1,s,str,ans);
            }
        }
        
    }
    vector<string> letterCasePermutation(string s) {
        int n=s.size();
        vector<string> ans;
        string str;
        check(0,s,str,ans);
        return ans;
    }
};