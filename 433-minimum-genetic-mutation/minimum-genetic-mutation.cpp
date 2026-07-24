class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>> q;
        map<string,int> mpp,vis;
        for(string i : bank){
            mpp[i] = 1;
        }
        char ch[4] = {'A','C','G','T'};
        q.push({startGene,0});
        mpp[startGene] = 1;
        vis[startGene] = 1;
        int ans=INT_MAX;
        while(!q.empty()){
            auto [str,d] = q.front();
            q.pop();
            if(str == endGene){
                ans = min(ans,d);
            }
            cout<<str<<" ";
            for(int i=0;i<8;i++){
                char c=str[i];
                for(int j=0;j<4;j++){
                    str[i] = ch[j];
                    if(mpp[str] == 1 && vis[str] == 0){
                        q.push({str,d+1});
                        vis[str] = 1;
                    }
                }
                str[i]=c;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};