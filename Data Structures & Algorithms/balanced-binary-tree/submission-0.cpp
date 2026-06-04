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
    bool isBalanced(TreeNode* root) {
        
        if(root==nullptr){
            return true;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(!left || !right) return false;

        int l = count(root->left);
        int r = count(root->right);

        if(abs(l-r)>1) return false;
        
        return true;
    }
    int count(TreeNode *root){
        if(root==nullptr){
            return 0;
        }
        int l = count(root->left);
        int r = count(root->right);

        return max(l,r)+1;
    }

};
