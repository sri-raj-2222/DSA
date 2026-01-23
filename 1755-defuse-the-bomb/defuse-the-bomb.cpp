class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> arr(code.size());
        if(k>0){
            for(int i=0;i<code.size();i++){
                int a=0;
                for(int j=i+1;j<=i+k;j++){
                    int t=j%code.size();
                    a+=code[t];
                }
                arr[i]=a;
            }
        }
        else if(k<0){
            for(int i=code.size()-1;i>=0;i--){
                int a=0;
                for(int j=i-1;j>=i+k;j--){
                    int t=(j+code.size())%code.size();
                    a+=code[t];
                }
                arr[i]=a;
            }
        }
        else{
            for(int i=0;i<code.size();i++) arr[i]=0;
        }
        return arr;
    }
};