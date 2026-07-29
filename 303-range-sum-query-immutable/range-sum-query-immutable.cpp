class NumArray {
public:
int n;
vector<int> pre;
    NumArray(vector<int>& nums) {
        n=nums.size();
        pre.assign(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1]+nums[i];
        }
    }
    int sumRange(int left, int right) {
        if(left == 0) return pre[right];
        else return pre[right] - pre[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */