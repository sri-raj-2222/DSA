class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        int row[4]={-1,0,0,1};
        int col[4]={0,-1,1,0};
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        >pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto [time,pos]=pq.top();
            auto [r,c]=pos;
            pq.pop();
            if(r==n-1 && c==m-1) return time;
            for(int i=0;i<4;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int nextTime=max(time+1,grid[nr][nc]+1);
                    if(dist[nr][nc] > nextTime){
                        dist[nr][nc]=nextTime;
                        pq.push({nextTime,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};