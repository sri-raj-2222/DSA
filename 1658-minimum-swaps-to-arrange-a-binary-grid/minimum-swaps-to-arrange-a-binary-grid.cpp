class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> zeros;
        int n=grid.size();
        // cout<<n;
        for(int i=0;i<n;i++){
            int zero=0;
            for(int j=n-1;j>=1;j--){
                if(grid[i][j]==0){
                    zero++;
                }
                else break;
            }
            zeros.push_back(zero);
        }
        // for(int i=0;i<zeros.size();i++) cout<<zeros[i]<<" ";
        int k=n-1;
        int start=0,ans=0;
        while(k > 0){
            bool flag=false;
            for(int i=start;i<zeros.size();i++){
                if(zeros[i] >= k){
                    int val=zeros[i];
                    zeros.erase(zeros.begin() + i);
                    zeros.insert(zeros.begin() + start, val);
                    ans+=(i-start);
                    flag=true;
                    break;
                }
            }
            if(!flag) return -1;
            start++;
            k--;
        }
        return ans;
    }
};