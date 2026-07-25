class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;
        int row[4] = {0,0,1,-1};
        int col[4] = {1,-1,0,0};
        pq.push({0,0,0});
        while(!pq.empty()){
            auto [d,r,c] = pq.top();
            pq.pop();
            for(int i=0;i<4;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int nd = max(d,abs(heights[r][c] - heights[nr][nc]));
                    if(dist[nr][nc] > nd){
                        dist[nr][nc] = nd;
                        pq.push({nd,nr,nc});
                    }
                }
            }
        }
        return dist[n-1][m-1] == INT_MAX ? 0 : dist[n-1][m-1];
    }
};