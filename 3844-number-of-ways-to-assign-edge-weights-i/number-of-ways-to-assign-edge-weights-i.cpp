class Solution {
public:
const int MOD = 1e9 + 7;
long long modPow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
    int assignEdgeWeights(vector<vector<int>>& edges) {
        vector<vector<int>> mat(edges.size()+2);
        for(auto &i : edges){
            mat[i[0]].push_back(i[1]);
        }
        queue<pair<int,int>> q;
        q.push({1,0});
        int maxi = 0;
        while(!q.empty()){
            auto [node,h] = q.front();
            q.pop();
            maxi = max(h,maxi);
            for(int v : mat[node]){
                q.push({v,h+1});
            }
        }
        if(maxi == 0) return 2;
        return modPow(2,maxi-1);
    }
};