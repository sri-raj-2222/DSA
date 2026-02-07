class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b')st.push(s[i]);
            else if(st.size()>0){
                st.pop();
                cnt++;
            }
        }
        return cnt;
    }
};