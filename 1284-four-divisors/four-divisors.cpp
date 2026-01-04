class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int cnt=0,temp=0;
            for(int j=1;j<=sqrt(a);j++){
                if(a%j==0){
                    if(j*j==a){
                        cnt++;
                        temp+=j;
                    }
                    else{
                        cnt+=2;
                        temp+=j;
                        temp+=(a/j);
                    }
                }
            }
            if(cnt==4){
                ans+=temp;
            }
        }
        return ans;
    }
};