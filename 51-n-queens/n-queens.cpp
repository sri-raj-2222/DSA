class Solution {
public:
    vector<vector<string>> ans;
    bool check(int i,int j,vector<string> &board){
        int n=board.size();
        for(int k=0;k<n;k++){
            if(board[i][k] == 'Q') return false;
            if(board[k][j] == 'Q') return false;
        }
        int l=i,r=j;
        while(l>=0 && r>=0){
            if(board[l][r] == 'Q') return 0;
            l--;
            r--;
        }
        l=i,r=j;
        while(l>=0 && r<=n-1){
            if(board[l][r] == 'Q') return 0;
            l--;
            r++;
        }
        return 1;
    }
    bool solve(int i,vector<string> &s,int n){
        if(i==n){
            ans.push_back(s);
            return 1;
        }
        for(int l=0;l<n;l++){
            if(check(i,l,s)){
                s[i][l] = 'Q';
                solve(i+1,s,n);
                s[i][l] = '.';
            }
        }
        return 0;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> s(n,string(n,'.'));
        solve(0,s,n);
        return ans;
    }
};