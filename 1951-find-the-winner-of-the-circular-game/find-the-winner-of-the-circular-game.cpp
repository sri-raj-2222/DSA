class Solution {
public:
    int findTheWinner(int n, int k) {
        list<int> l;
        for(int i=0;i<n;i++){
            l.push_back(i+1);
        }
        int cnt=0;
        auto i=l.begin();
        while(l.size() > 1){
            cnt++;
            if(cnt==k){    
                auto nextIt=next(i);    
                cnt=0;
                l.erase(i);
                if(nextIt==l.end()) nextIt=l.begin();
                i=nextIt;
                
            }
            else{
                ++i;
                if(i==l.end()) i=l.begin();
            }
            
        }
        auto it=l.begin();
        return *it;
    }
};