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
    TreeNode* cur;
    void dfs(TreeNode* root,int x){
        if(!root) return;
        if(root->val == x) cur = root;
        dfs(root->left,x);
        dfs(root->right,x);
    }
    int count(TreeNode* root){
        if(!root) return 0;
        return 1+count(root->left)+count(root->right);
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        build(root);
        dfs(root,x);
        int a=0,b=0,c=0;
        if(cur->left) a=count(cur->left);
        if(cur->right) b=count(cur->right);
        c=n-(a+b+1);
         if(max({a,b,c}) > n/2) return true;
         else return false;
    }
};