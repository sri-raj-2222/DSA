class Solution {
public:
    void rotate(vector<vector<int>> & mat){
        int n=mat.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool check(vector<vector<int>> &mat,vector<vector<int>> &tar){
        return mat == tar;
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