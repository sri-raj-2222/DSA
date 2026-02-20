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
    void dfs(TreeNode* p,TreeNode* q,int level){
        if(!p || !q) return;
        if(level%2==0) swap(p->val,q->val);
        level++;
        dfs(p->left,q->right,level);
        dfs(p->right,q->left,level);

    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return NULL;
        dfs(root->left,root->right,0);
        return root;
    }
};