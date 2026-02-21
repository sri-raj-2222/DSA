class Solution {
public:
      bool prime(long long n){
        if(n==1 or n==0) return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
      }
    long long splitArray(vector<int>& nums) {
        long long sum=0,psum=0;
        for(int i=0;i<nums.size();i++){
            if(prime(i)==true) psum+=1LL*nums[i];
            else sum+=1LL*nums[i];
        }
        return llabs(psum-sum);
    }
};