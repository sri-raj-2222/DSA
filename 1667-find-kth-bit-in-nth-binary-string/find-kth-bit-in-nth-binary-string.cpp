class Solution {
public:
    char findKthBit(int n, int k) {
        string str="0";
        string temp="";
        while(n-1){
            string s=str+"1";
            string rev;
            for(int i=0;i<str.size();i++){
                if(str[i]=='1'){
                    rev+='0';
                }
                else rev+='1';
            }
            reverse(rev.begin(),rev.end());
            s+=rev;
            str=s;
            n--;
        }
        return str[k-1];
    }
};