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
    int sum(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        int left=sum(root->left);
        int right=sum(root->right);
        return left+right+root->val;
    }
    int count(TreeNode* root){
        if(!root) return 0;
        return 1+count(root->left)+count(root->right);
    }
    int cnt=0;
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        if(sum(root)/count(root) == root->val) cnt++;
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        return cnt;
    }
};