class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MIN));
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({0,i,j});
                    dist[i][j] = 0;
                }
            }
        }
        int row[4] = {0,0,1,-1};
        int col[4] = {1,-1,0,0};
        int ans = 0;
        while(!q.empty()){
            auto [d,r,c] = q.top();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc]==INT_MIN){
                    dist[nr][nc] = d+1;
                    ans=max(ans,d+1);
                    q.push({d+1,nr,nc});
                }
            }
        }
        return ans == 0 ? -1 : ans;
    }
};