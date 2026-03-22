class Solution {
public:
    void rotate(vector<vector<int>> & mat){
        int n=mat.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool check(vector<vector<int>> &mat,vector<vector<int>> &tar){
        int n = mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] != tar[i][j]) return 0;
            }
        }
        return 1;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& tar) {
        bool a = check(mat,tar);
        rotate(mat);
        bool b = check(mat,tar);
        rotate(mat);
        bool c = check(mat,tar);
        rotate(mat);
        bool d = check(mat,tar);
        return a || b ||c || d;
    }
};