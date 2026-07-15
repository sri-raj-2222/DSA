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
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                char ch=board[i][j];
                board[i][j] = '.';
                if(!check(board,i,j,ch)) return false;
            }
        }
        return true;
    }
};