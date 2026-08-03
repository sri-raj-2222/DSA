class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(grumpy[i] == 0) ans += customers[i];
        }
        int sum = 0;
        for(int i=0;i<minutes;i++){
            if(grumpy[i] == 1){
                sum += customers[i];
            }
        }
        int maxi =  sum;
        for(int i=minutes;i<n;i++){
            if(grumpy[i-minutes] == 1){
                sum-=customers[i-minutes];
            }
            if(grumpy[i] == 1){
                sum += customers[i];
            }
            maxi = max(maxi,sum);
        }
        return ans + maxi;
    }
};