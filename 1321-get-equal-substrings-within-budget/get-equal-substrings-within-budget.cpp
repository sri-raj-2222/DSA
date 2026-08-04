class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int i=0,cost=0,maxi = 0;
        for(int j=0;j<n;j++){
            cost += abs(s[j] - t[j]);
            while(cost > maxCost){
                cost -= abs(s[i] - t[i]);
                i++;
            }
            maxi = max(maxi,j-i+1);
        }
        return maxi;
    }
};