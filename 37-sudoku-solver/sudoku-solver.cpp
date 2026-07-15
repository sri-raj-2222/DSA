class Solution {
public:
    bool check(vector<vector<char>> &board,int i,int j,char ch){
        for(int k=0;k<9;k++){
            if(ch == board[i][k]) return false;
            if(ch == board[k][j]) return false;
        }
        int start = i/3,end =j/3;
        start *= 3,end *=3;
        for(int l=start;l<start+3;l++){
            for(int m=end;m<end+3;m++){
                if(board[l][m] == ch) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board,int i,int j){
        if(j == 9){
            i+=1;
            j=0;
        }
        if(i == 9) return 1;
        if(board[i][j] != '.'){
            return solve(board,i,j+1);
        }
        for(int l=1;l<10;l++){
            if(check(board,i,j,l+'0')){
                board[i][j] = l+'0';
                if(solve(board,i,j+1)) return 1;
                board[i][j] = '.';
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};