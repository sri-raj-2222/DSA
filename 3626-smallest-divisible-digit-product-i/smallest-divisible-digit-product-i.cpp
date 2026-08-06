class Solution {
public:
    int smallestNumber(int n, int t) {
        int a,val;
        while(1){
            a=n,val = 1;
            while(a){
                int rem = a%10;
                val *= rem;
                a/=10;
            }
            if(val%t == 0){
                return n;
            }
            n++;
        }
        return -1;
    }
};