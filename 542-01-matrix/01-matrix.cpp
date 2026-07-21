class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<tuple<int,int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m));
        vector<vector<int>> dist(n,vector<int>(m));
        int row[4] = {0,0,1,-1};
        int col[4] = {1,-1,0,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    for(int k=0;k<4;k++){
                        int nr=i+row[k];
                        int nc=j+col[k];
                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && mat[nr][nc] == 1){
                            q.push({nr,nc,1});
                            vis[nr][nc] = 1;
                            dist[nr][nc] = 1;
                        }
                    }
                }
            }
        }
        while(!q.empty()){
            auto [r,c,d] = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+row[k];
                int nc=c+col[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && mat[nr][nc] == 1){
                    vis[nr][nc] = 1;
                    dist[nr][nc] =  1 + d;
                    q.push({nr,nc,1+d});
                }
            }
        }
        return dist;

    }
};