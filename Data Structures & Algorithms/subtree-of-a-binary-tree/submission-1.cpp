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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr){
            return false;
        }
        if(root->val == subRoot->val){
            if(isTree(root,subRoot)){
                return true;
            }
        }
        bool left = isSubtree(root->left,subRoot);
        bool right = isSubtree(root->right,subRoot);
        if(left || right){
            return true;
        }
        return false;
    }
    bool isTree(TreeNode *root, TreeNode * subRoot){
        if(root==nullptr && subRoot==nullptr){
            return true;
        }
        if(root==nullptr || subRoot==nullptr || root->val != subRoot->val){
            return false;
        }
       
        bool left = isTree(root->left,subRoot->left);
        bool right = isTree(root->right,subRoot->right);
        if(left && right){
            return true;
        }
        return false;
    }
};
