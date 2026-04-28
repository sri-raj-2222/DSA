class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        map<int,int> mpp;
        for (int i = 1 ; i*i*i <= n ; i++){
            for(int j = 1 ; j <= i-1 ; j++){
                if((i*i*i + j*j*j) <= n) mpp[(i*i*i + j*j*j)]++;
            }
        }
        vector<int> arr;
        for(auto i : mpp){
            if(i.second > 1){
                arr.push_back(i.first);
            }
        }
        return arr;
    }
};