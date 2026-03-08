class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        vector<pair<int,int>> arr;
        int idx=0;
        for(int i : capacity){
            arr.push_back({i,idx++});
        }
        sort(arr.begin(),arr.end());
        for(auto &[val,i] : arr){
            if(val >= itemSize){
                return i;
            }
        }
        return -1;
    }
};