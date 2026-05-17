class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0) return 1;
        int n = arr.size();
        vector<int> vis(n);
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while(!q.empty()){
            int idx =  q.front();
            q.pop();
            if(arr[idx] == 0) return true;
            else{
                if(idx - arr[idx] >= 0 && !vis[idx - arr[idx]]){
                    q.push(idx - arr[idx]);
                    vis[idx - arr[idx]] = 1;
                }
                if(idx + arr[idx] < n && !vis[idx + arr[idx]]){
                    q.push(idx + arr[idx]);
                    vis[idx + arr[idx]] = 1;
                }
            }
        }
        return false;
    }
};