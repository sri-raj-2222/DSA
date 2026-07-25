class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(n));
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        int row[4] = {0,0,1,-1};
        int col[4] = {1,-1,0,0};
        int cnt = 2;
        bool flag=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    grid[i][j] = cnt;
                    vis[i][j]=1;
                    while(!q.empty()){
                        auto  [r,c] = q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nr=r+row[k];
                            int nc=c+col[k];
                            if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                                if(grid[nr][nc] == 1){
                                    grid[nr][nc] = cnt;
                                    q.push({nr,nc});
                                }
                                else if(cnt==2 && !vis[nr][nc]){
                                    pq.push({0,nr,nc});
                                    vis[nr][nc]=1;
                                }
                            }
                        }
                    }
                    cnt++;
                    if(cnt == 4){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag) break;
        }
        while(!pq.empty()){
            auto [d,r,c] = pq.top();
            pq.pop();
            if(grid[r][c] == 3){
                return d;
            }
            for(int i=0;i<4;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] != 2){
                    if(dist[nr][nc] > d+1){
                        dist[nr][nc]=1;
                        pq.push({d+1,nr,nc});
                    }
                }
            }
        }
        return 0;
    }
};