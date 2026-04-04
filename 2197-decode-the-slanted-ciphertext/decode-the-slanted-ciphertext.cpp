class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string str;
        int n=encodedText.size();
        vector<string> arr;
        string temp="";
        int bre=n/rows;
        for(int i=0;i<n;i++){
            temp+=encodedText[i];
            if((i+1)%bre == 0){
                arr.push_back(temp);
                temp="";
            }
        }
        string s="";
        for(int i=0;i<bre;i++){
            int a=0,b=i;
            while(a < rows && b < bre){
                s+=arr[a][b];
                a++;b++;
            }
        }
        s.erase(s.find_last_not_of(' ') + 1);
        return s;
    }
};