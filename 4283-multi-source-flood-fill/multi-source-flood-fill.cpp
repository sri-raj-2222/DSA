class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> ans(n,vector<int>(m,0));
        sort(sources.begin(),sources.end(),[&](auto a,auto b){
            return a[2] > b[2];
        });
        queue<tuple<int,int,int>> q;
        for(auto i : sources){
            q.push({i[0],i[1],i[2]});
            ans[i[0]][i[1]] = i[2];
        }
        int row[4] = {0,0,1,-1};
        int col[4] = {1,-1,0,0};
        while(!q.empty()){
            auto [r,c,co] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc] == 0){
                    ans[nr][nc] = co;
                    q.push({nr,nc,co});
                }
            }
        }
        return ans;
    }
};