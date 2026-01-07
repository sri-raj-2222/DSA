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
    long long maxi=LLONG_MIN;
    long long sum=0;
    int dfs(TreeNode* root){
        if(!root) return 0;
         return root->val+dfs(root->left)+dfs(root->right);
    }
    long long helper(TreeNode* root){
        if(!root) return 0;
        long long left=helper(root->left);
        long long right=helper(root->right);
        long long sub=root->val+left+right;
        long long pro=(sum-sub)*sub;
        maxi=max(maxi,pro);
        return sub;
    }
    int maxProduct(TreeNode* root) {
        if(!root) return 0;
        sum=dfs(root);
        helper(root);
        return maxi%1000000007;
    }
};