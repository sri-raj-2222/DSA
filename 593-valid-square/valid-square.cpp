class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int a = pow(p2[0]-p1[0],2) + pow(p2[1]-p1[1],2);
        int b = pow(p3[0]-p1[0],2) + pow(p3[1]-p1[1],2);
        int c = pow(p4[0]-p1[0],2) + pow(p4[1]-p1[1],2);
        int d = pow(p3[0]-p2[0],2) + pow(p3[1]-p2[1],2);
        int e = pow(p4[0]-p2[0],2) + pow(p4[1]-p2[1],2);
        int f = pow(p4[0]-p3[0],2) + pow(p4[1]-p3[1],2);
        map<int,int>mpp;
        mpp[a]++;
        mpp[b]++;
        mpp[c]++;
        mpp[d]++;
        mpp[e]++;
        mpp[f]++;
        if(mpp.count(0)) return false;
        if(mpp.size() != 2) return false;
        for(auto it : mpp){
            if(it.second != 2 && it.second != 4) return false;
        }
        return true;
    }
};