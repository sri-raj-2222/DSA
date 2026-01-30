class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mpp;
        vector<int> nums;
        for(int i : arr1) mpp[i]++;
        for(int i : arr2){
            while(mpp[i] > 0){
                nums.push_back(i);
                mpp[i]--;
            }
        }
        for(auto i : mpp){
            if(i.second > 0){
                while(i.second > 0){
                    nums.push_back(i.first);
                    i.second--;
                }
            }
        }
        return nums;
    }
};