class Solution {
public:
    vector<string>str={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void check(string digit,string &ds,int ind,int n ,vector<string>&ans){
        if(digit.size()==ds.size()){
            ans.push_back(ds);
            return ;
        }
        if(ind==n) return ;
        for(int i=0;i<str[digit[ind]-'0'].size();i++){
            ds+=str[digit[ind]-'0'][i];
            check(digit,ds,ind+1,n,ans);
            ds.pop_back();
        }  
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        string ds;
        vector<string>ans;
        check(digits,ds,0,n,ans);
        return ans;
    }
};