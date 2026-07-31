class Solution {
public:

    TreeNode* LCA(TreeNode* root, int p, int q) {
        if (!root) return nullptr;

        if (root->val == p || root->val == q)
            return root;

        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);

        if (left && right)
            return root;

        return left ? left : right;
    }

    bool findPath(TreeNode* root, int target, string &path) {

        if (!root)
            return false;

        if (root->val == target)
            return true;

        path.push_back('L');
        if (findPath(root->left, target, path))
            return true;
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, target, path))
            return true;
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {

        TreeNode* lca = LCA(root, startValue, destValue);

        string sPath, dPath;

        findPath(lca, startValue, sPath);
        findPath(lca, destValue, dPath);

        return string(sPath.size(), 'U') + dPath;
    }
};