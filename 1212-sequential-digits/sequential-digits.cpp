class Solution {
public:
    vector<int> arr;
    void solve(int sum,int low,int high,int start){
        int ll=log10(low)+1;
        int hl=log10(high)+1;
        int sl;
        sum == 0 ? sl=0 : sl = log10(sum)+1;
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