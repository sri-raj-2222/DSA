/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> tree;
   void build(TreeNode* root) {
        if (!root) return;
        if (root->left) {
            tree[root->left] = root;
            build(root->left);
        }
        if (root->right) {
            tree[root->right] = root;
            build(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        build(root);
        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis.insert(target);
        vector<int> ans;
        while(!q.empty()){
            if(k==0) break;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(tree[node] && vis.find(tree[node])==vis.end()){
                    q.push(tree[node]);
                    vis.insert(tree[node]);
                }
                if(node->left && vis.find(node->left)==vis.end()){
                    q.push(node->left);
                    vis.insert(node->left);
                }
                if(node->right && vis.find(node->right)==vis.end()){
                    q.push(node->right);
                    vis.insert(node->right);
                }
            }
            k--;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};