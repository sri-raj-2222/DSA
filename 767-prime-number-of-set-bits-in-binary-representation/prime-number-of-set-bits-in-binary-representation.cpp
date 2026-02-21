class Solution {
public:
    int countOnes(int n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1);
            n = n >> 1;      
        }
        return count;
    }
    bool prime(int n){
        int count=0;
        for(int i=1;i<=n;i++){
            if(n%i==0) count++;
        }
        return count==2;
    }
    int ans=0;
    int countPrimeSetBits(int left, int right) {
        for(int i=left;i<=right;i++){
            int cnt=countOnes(i);
            if(prime(cnt)) ans++;
        }   
        return ans;
    }
};