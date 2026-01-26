class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int mini=INT_MAX;
        vector<vector<int>> nums;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++){
            mini=min(mini,arr[i+1]-arr[i]);
        }
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i] == mini){
                nums.push_back({arr[i],arr[i+1]});
            }
        }
        return nums;
    }
};