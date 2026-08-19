class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& nums) {
        map<int,vector<int>> mpp;
        sort(nums.begin(),nums.end());
        for(auto arr : nums){
            mpp[arr[0]].push_back(arr[1]);
        }
        int ans = 0;
        for(auto it : mpp){
            int val = it.first;
            vector<int> temp = it.second;
            int c1=0,c2=0,c3=0;
            for(int i=0;i<temp.size();i++){
                int a = temp[i];
                if(a == 2 || a==3) c1=1;
                else if(a==4 || a==5){
                    c1 = 1;
                    c2 = 1;
                }
                else if(a==6 || a==7){
                    c2=1;
                    c3=1;
                }
                else if(a==8 || a==9){
                    c3=1;
                }
            }
            if(c1 == 0 && c2 == 0 && c3 == 0){
                ans+=2;
            }
            else if(c1+c2+c3 <= 2) ans += 1;
            
        }
        int m = n-mpp.size();
        ans += 2*m;
        return ans;
    }
};