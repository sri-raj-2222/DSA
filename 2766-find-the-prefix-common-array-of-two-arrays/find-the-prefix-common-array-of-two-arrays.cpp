class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        map<int,int> mpp;
        vector<int> arr;
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            mpp[A[i]]++;
            if(mpp[A[i]] ==  2) cnt++;
            mpp[B[i]]++;
            if(mpp[B[i]] ==  2) cnt++;
            arr.push_back(cnt);
        }
        return arr;
    }
};