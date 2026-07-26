class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;
        int row[8] = {0,0,1,-1,1,-1,1,-1};
        int col[8] = {1,-1,1,-1,0,0,-1,1};
        if(grid[0][0] == 1) return -1;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0] = 0;
        pq.push({1,0,0});
        while(!pq.empty()){
            auto [d,r,c] = pq.top();
            pq.pop();
            if(r == n-1 && c == n-1){
                return d;
            }
            for(int i=0;i<8;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0){
                    if(dist[nr][nc] > d+1){
                        dist[nr][nc] = d+1;
                        pq.push({d+1,nr,nc});
                    }
                }
            }
        }
        return -1;
    }
};