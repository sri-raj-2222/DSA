class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>
        > pq;
        int row[4] = {0,0,1,-1};
        int col[4] = {1,-1,0,0};
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            auto [d,r,c] = pq.top();
            pq.pop();
            for(int i=0;i<4;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                    int nd = max(d,grid[nr][nc]);
                    if(dist[nr][nc] > nd){
                        dist[nr][nc] = nd;
                        pq.push({nd,nr,nc});
                    }
                }
            }
        }
        return dist[n-1][n-1];

    }
};