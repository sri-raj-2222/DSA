class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            int flag=0;
            if(arr[i]>0){
                st.push(arr[i]);
            }
            else if (st.empty() || (arr[i] < 0 && st.top() < 0)){
                st.push(arr[i]);
            }
            else  if (arr[i] < 0 && st.top() > 0){
                while(!st.empty() && st.top() > 0){
                    int t=st.top();
                    if(t==abs(arr[i])){
                        st.pop();
                        flag=1;
                        break;
                    }
                    else if(t == min(abs(arr[i]),t)){
                        st.pop();
                    }
                    else{
                        flag=1;
                        break;
                    }
                }
                if(flag==0) st.push(arr[i]);
            }
        }
        vector<int> nums;
        while(!st.empty()){
            nums.push_back(st.top());
            st.pop();
        }
        reverse(nums.begin(),nums.end());
        return nums;
    }
};