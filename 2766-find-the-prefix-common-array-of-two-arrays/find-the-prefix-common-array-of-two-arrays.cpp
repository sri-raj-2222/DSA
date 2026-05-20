class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        map<int,int> mpp;
        vector<int> arr;
        for(int i = 0 ; i < n ; i++){
            int cnt = 0;
            mpp[A[i]] = 1;
            for(int j = 0 ; j <= i ; j++){
                if(mpp[B[j]] == 1) cnt++;
            }
            arr.push_back(cnt);
        }
        return arr;
    }
};