/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
unordered_map<TreeNode*,TreeNode*> parent;
    void build(TreeNode* root){
        if(!root) return;
        if(root->left){
            parent[root->left]=root;
            build(root->left);
        }
        if(root->right){
            parent[root->right]=root;
            build(root->right);
        }
    }
    int ans=0;
    void dfs(TreeNode* root,int d){
        if(!root) return;
        if(!root->left && !root->right){
            ans+=check(root,d);
        }
        dfs(root->left,d);
        dfs(root->right,d);
    }
    int check(TreeNode* root,int nd){
        queue<pair<TreeNode*,int>> q;
        unordered_set<TreeNode*> vis;
        q.push({root,0});
        vis.insert(root);
        int cnt=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto [cur,d]=q.front();
                q.pop();
                if(d > nd) continue;
                if(d!=0 && !cur->left && !cur->right) cnt++;
                if(parent[cur] && vis.find(parent[cur])==vis.end()){
                    q.push({parent[cur],d+1});
                    vis.insert(parent[cur]);
                }
                if(cur->left && vis.find(cur->left)==vis.end()){
                    q.push({cur->left,d+1});
                    vis.insert(cur->left);
                }
                if(cur->right && vis.find(cur->right)==vis.end()){
                    q.push({cur->right,d+1});
                    vis.insert(cur->right);
                }
            }
        }
        return cnt;
    }
    int countPairs(TreeNode* root, int d) {
        build(root);
        dfs(root,d);
        return ans/2;
    }
};