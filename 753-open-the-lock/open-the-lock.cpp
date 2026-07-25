class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        map<string,int> mpp;
        for(string s : deadends) mpp[s] = 1;
        if(mpp["0000"] == 1) return -1;
        priority_queue<
        pair<int,string>,
        vector<pair<int,string>>,
        greater<pair<int,string>>
        > q;
        q.push({0,"0000"});
        mpp["0000"] = -1;
        int r[2] = {1,9};
        while(!q.empty()){
            auto [d,str] = q.top();
            q.pop();
            cout<<str<<" ";
            if(str == target){
                return d;
            }
            for(int i=0;i<4;i++){
                string temp = str;
                for(int j=0;j<2;j++){
                    str[i] = (str[i] - '0' + r[j]) % 10 + '0';
                    if(mpp[str] != 1 && mpp[str] != -1){
                        mpp[str] = -1;
                        q.push({d+1,str});
                    }
                    str = temp;
                }
            }
        }
        return -1;
    }
};