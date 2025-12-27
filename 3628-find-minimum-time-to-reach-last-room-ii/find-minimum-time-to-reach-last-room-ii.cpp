class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int row[4]={-1,0,0,1};
        int col[4]={0,-1,1,0};
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        >pq;
        int val=0;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            auto [d,pos]=pq.top();
            auto [r,c]=pos;
            pq.pop();
            for(int i=0;i<4;i++){
                int nr=row[i]+r;
                int nc=col[i]+c;
                int nd=(r+c)%2+1;
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    nd+=max(grid[nr][nc],d);
                    if(dist[nr][nc] > nd){
                        dist[nr][nc]=nd;
                        pq.push({nd,{nr,nc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};