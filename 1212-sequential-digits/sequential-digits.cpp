class Solution {
public:
    vector<int> arr;
    void solve(int sum,int low,int high,int start){
        if(sum >= low && sum <= high){
            arr.push_back(sum);
        }
        if(start > 9) return;
        solve(sum*10+start,low,high,start+1);

    }
    vector<int> sequentialDigits(int low, int high) {
        int sum=0;
        for(int i=1;i<=9;i++){
            solve(sum,low,high,i);
        }
        sort(arr.begin(),arr.end());
        return arr;
    }
};