/*Given the root of a binary tree, return the preorder traversal of its nodes' values.

Input: root = [1,null,2,3]
Output: [1,2,3]


Input: root = []
Output: []

Input: root = [1]
Output: [1]
*/
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
    void TraverseRecursively(TreeNode* root, vector<int> &X)
    {
        TreeNode *curr = root;
        //Left
        if(curr->left)
        {
            X.push_back(curr->left->val);
            TraverseRecursively(curr->left, X);
        }
        //Right
        curr = root;
        if(curr->right)
        {
            X.push_back(curr->right->val);
            TraverseRecursively(curr->right, X);
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> X;
        if(root)
            X.push_back(root->val);
        else
            return X;
        
        TraverseRecursively(root, X);
        return X;
    }
};
