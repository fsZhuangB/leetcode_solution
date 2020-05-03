#include <queue>

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

// this solution I use BFS, we have to maintain a varible named depth
// when iteration stops, we can find the depth of the bintree
class Solution2 {
    public:
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        std::queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty())
        {
            // 每次循环，depth++
            depth++;
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode* p = q.front();
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
        }
        return depth;
    }

};