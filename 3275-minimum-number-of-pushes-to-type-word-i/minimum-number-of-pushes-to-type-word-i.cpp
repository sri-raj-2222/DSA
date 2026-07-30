class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int a = n/8;
        int rem = n%8,ans=0;
        int cnt=1;
        ans += ((a*(a+1))/2 * 8);
        ans += (a+1)*rem;
        return ans;
    }
};