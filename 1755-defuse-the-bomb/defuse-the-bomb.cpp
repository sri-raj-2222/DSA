class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        if(k < 0) reverse(code.begin(),code.end());
        vector<int> arr(n);
        arr[0]=code[0];
        for(int i=1;i<n;i++){
            arr[i] = code[i]+arr[i-1];
        }
        int p=abs(k);
        vector<int> ans(n);
        if(k==0) return ans;
        for(int i=0;i<n;i++){
            if(i+p < n) ans[i] = abs(arr[i] - arr[i+p]);
            else ans[i] = abs(arr[i] - arr[n-1]) + arr[(i+p)%n];
        }
        if(k < 0){
            reverse(ans.begin(),ans.end());
            return ans;
        }
        else return ans;
    }
};