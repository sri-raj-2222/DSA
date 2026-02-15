class Solution {
public:
    string addBinary(string a, string b) {
        char carry='0';
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ans;
        int n=min(a.size(),b.size());
        for(int i=0;i<n;i++){
            if(carry=='0'){
                if(a[i]=='0' && b[i]=='0') ans.push_back('0');
                else if(a[i]=='0' && b[i]=='1') ans.push_back('1');
                else if(a[i]=='1' && b[i]=='0') ans.push_back('1');
                else{
                    ans.push_back('0');
                    carry='1';
                }

            }
            else{
                if(a[i]=='0' && b[i]=='0'){
                    ans.push_back('1');
                    carry='0';
                }
                else if(a[i]=='0' && b[i]=='1'){
                    ans.push_back('0');
                    carry='1';
                }
                else if(a[i]=='1' && b[i]=='0'){
                    ans.push_back('0');
                    carry='1';
                }
                else{
                    ans.push_back('1');
                    carry='1';
                }
            }
        }
        int p=n;
        if(n == a.size()){
            for(int i=p;i<b.size();i++){
                if(carry=='0'){
                    ans.push_back(b[i]);
                }
                else{
                    if(b[i]=='0'){
                        ans.push_back('1');
                        carry='0';
                    }
                    else{
                        ans.push_back('0');
                    }
                }   
            }       
        }
        else{
            if(n == b.size()){
                for(int i=p;i<a.size();i++){
                    if(carry=='0'){
                        ans.push_back(a[i]);
                    }
                    else{
                        if(a[i]=='0'){
                            ans.push_back('1');
                            carry='0';
                        }
                        else{
                            ans.push_back('0');
                        }
                    }   
                }       
            }
        }
        if(carry=='1') ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};