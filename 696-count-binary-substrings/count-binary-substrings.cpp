class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt=1,ans=0;
        bool flag=0;
        vector<int> arr;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                cnt++;
            }
            else{
                arr.push_back(cnt);
                cnt=1;
            }
        }
        arr.push_back(cnt);
        for(int i=0;i<arr.size()-1;i++){
            ans+=min(arr[i],arr[i+1]);
        }
        return ans;
    }
};