
class TreeNode
{
    public:
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(int a, TreeNode* l, TreeNode* r) : val(e), left(l), right(r) {}
};

/**
 * The simplest Solution is to use recursion
 * Pay attention to the return statement: you have to add 1 because of the root' s depth
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        
        return std::max(leftHeight, rightHeight) + 1;
    }
};