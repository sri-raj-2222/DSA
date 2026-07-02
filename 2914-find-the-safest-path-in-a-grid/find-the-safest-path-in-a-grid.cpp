class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        int row[4]={0,0,1,-1};
        int col[4]={1,-1,0,0};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=row[i]+r;
                int nc=col[i]+c;
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1){
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
        priority_queue<tuple<int,int,int>> pq;
        vector<vector<int>> best(n,vector<int>(n,-1));
        pq.push({dist[0][0],0,0});
        while(!pq.empty()){
            auto [safe,r,c] = pq.top();
            if(r==n-1 && c==n-1) return safe;
            pq.pop();
            for(int i=0;i<4;i++){
                int nr=row[i]+r;
                int nc=col[i]+c;
                if(nr>=0 && nr<n && nc>=0 && nc<n){
                    int nsafe=min(safe,dist[nr][nc]);
                    if(nsafe > best[nr][nc]){
                        best[nr][nc] = nsafe;
                        pq.push({nsafe,nr,nc});
                    }
                }
            }
        }
        return 0;
    }
};