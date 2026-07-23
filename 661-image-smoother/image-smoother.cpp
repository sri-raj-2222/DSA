class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        int row[8]={0,0,1,-1,1,-1,1,-1};
        int col[8]={1,-1,0,0,1,-1,-1,1};
        vector<vector<int>> ans = img;
        int sum=0,cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=img[i][j];
                cnt=1;
                for(int k=0;k<8;k++){
                    int nr=i+row[k];
                    int nc=j+col[k];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                        sum += img[nr][nc];
                        cnt++;
                    }
                }
                ans[i][j] = sum/cnt;
                sum=0;cnt=0;
            }
        }
        return ans;
    }
};