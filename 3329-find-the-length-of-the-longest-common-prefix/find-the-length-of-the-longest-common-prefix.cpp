class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mpp;
        for(int i = 0 ; i < arr1.size() ; i++){
            int x = arr1[i];
            while(x){
                mpp[x] = 1;
                x /= 10;
            }
        }
        for(auto i : mpp) cout<<i.first<<" "<<i.second;
        int maxi = -1;
        for(int i = 0 ; i < arr2.size() ; i++){
            int x = arr2[i];
            while(x){
                int len = log10(x)+1;
                if(mpp[x] == 1) maxi = max(maxi,len);
                x /= 10;
            }
        }
        return maxi == -1 ? 0 : maxi;
    }
};