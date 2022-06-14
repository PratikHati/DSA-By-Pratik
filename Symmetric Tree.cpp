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
class Solution
{
public:
    bool Solve(TreeNode *root1, TreeNode *root2)
    {

        if (root1->val != root2->val)
        {
            return false;
        }

        bool ans1 = true, ans2 = true;

        ////////////////////////////////////
        if (root1->left != NULL)
        {
            if (root2->right == NULL)
                return false;

            if (root1->left->val == root2->right->val)
            {
                ans1 = Solve(root1->left, root2->right);
            }
            else
                return false;
        }
        else
        {
            if (root2->right != NULL)
                ans1 = false;
        }

        //////////////////////////////////

        if (root1->right != NULL)
        {
            if (root2->left == NULL)
                return false;

            if (root1->right->val == root2->left->val)
            {
                ans2 = Solve(root1->right, root2->left);
            }
            else
                return false;
        }
        else
        {
            if (root2->left != NULL)
                ans2 = false;
        }

        return ans1 && ans2;
    }
    bool isSymmetric(TreeNode *root)
    {
        Symmetric Tree

            if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return true;
        }

        // devide into 2 different tree and comapre
        if (root->left != NULL && root->right != NULL)
            return Solve(root->left, root->right);
        else
            return false;
    }
};