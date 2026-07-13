class Solution {
public:
int row[4] = {0,0,-1,1};
int col[4] = {1,-1,0,0};
    bool solve(int i,int j,int ind,vector<vector<char>> &board ,string word,vector<vector<bool>> &vis){
        int n=board.size();
        int m=board[0].size();
        if(word[ind] != board[i][j]) return 0;
        if(word.size()-1 == ind) return 1;
        if(vis[i][j]) return 0;
        if(word[ind] == board[i][j]){
            vis[i][j] = 1;
            for(int k=0;k<4;k++){
                int r=i+row[k];
                int c=j+col[k];
                if(r>=0 && r<n && c>=0 && c<m && !vis[r][c]){
                    if(solve(r,c,ind+1,board,word,vis)){
                        vis[i][j] = 0;
                        return 1;
                    }
                }
            }
            vis[i][j] = 0;
        }
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(solve(i,j,0,board,word,vis)) return 1;
            }
        }
        return 0;
    }
};