class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<
        int,
        vector<int>,
        greater<int>
        > pq;
        pq.push(amount[0]);
        pq.push(amount[1]);
        pq.push(amount[2]);
        int ans = 0;
        while(1){
            int a = pq.top();
            pq.pop();
            if(a == 0) break;
            int b = pq.top();
            pq.pop();
            int c = pq.top();
            pq.pop();
            ans++;
            pq.push(--a);
            pq.push(b);
            pq.push(--c);
        }
        pq.pop();
        ans += pq.top();
        return ans;
    }
};