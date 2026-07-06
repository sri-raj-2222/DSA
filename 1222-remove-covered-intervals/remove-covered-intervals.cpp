class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        int n=arr.size();
        map<int,int> mpp;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i][0] <= arr[j][0] && arr[i][1] >= arr[j][1]){
                    mpp[j]=1;
                }
                if(arr[i][0] >= arr[j][0] && arr[i][1] <= arr[j][1]){
                    mpp[i]=1;
                }
            }
        }
        return arr.size()-mpp.size();
    }
};