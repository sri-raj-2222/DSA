class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>> q;
        unordered_map<string,int> mpp,vis;
        for(string i : bank){
            mpp[i] = 1;
        }
        char ch[4] = {'A','C','G','T'};
        q.push({startGene,0});
        mpp[startGene] = 1;
        while(!q.empty()){
            auto [str,d] = q.front();
            q.pop();
            if(str == endGene) return d;
            for(int i=0;i<8;i++){
                char c=str[i];
                for(int j=0;j<4;j++){
                    str[i] = ch[j];
                    if(mpp[str] == 1 && mpp[str] != -1){
                        q.push({str,d+1});
                        mpp[str] = -1;
                    }
                }
                str[i]=c;
            }
        }
        return -1;
    }
};