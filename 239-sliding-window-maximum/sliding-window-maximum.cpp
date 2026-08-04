class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        int prev = nums[0];
        dq.push_back(nums[0]);
        vector<int> ans;
        for(int i=1;i<k;i++){
            while(!dq.empty() && dq.back() < nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());
        for(int i=k;i<n;i++){
            if(nums[i-k] == dq.front()){
                dq.pop_front();
            }
            while(!dq.empty() && dq.back() < nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            prev = nums[i];
            ans.push_back(dq.front());
        }
        return ans;
    }
};