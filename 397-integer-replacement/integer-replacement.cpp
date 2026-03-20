class Solution {
public:
    int dfs(int n){
        if(n == 1) return 0;
        int cnt=0;
        if(n % 2 == 0){
            cnt +=1+dfs(n/2);
        }
        else {
            if(n == INT_MAX) cnt += dfs(n-1);
            else cnt += 1+min(dfs(n-1),dfs(n+1));
        }
        return cnt;
    }
    int integerReplacement(int n) {
        return dfs(n);
    }
};