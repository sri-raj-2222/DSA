class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        int app=0;
        for(int i=0;i<apple.size();i++){
            app+=apple[i];
        }
        for(int i=0;i<capacity.size();i++){
            app-=capacity[i];
            if(app<=0) return i+1;
        }
        return -1;
    }
};