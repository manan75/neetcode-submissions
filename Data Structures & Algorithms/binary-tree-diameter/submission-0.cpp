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
    int diameterOfBinaryTree(TreeNode* root) {
        
        int maxi = -1;
        int ans = solve(root,maxi);
        return maxi;
    }

    int solve(TreeNode * root, int &maxi){
        if(root==nullptr){
            return 0;
        }
        int left = solve(root->left,maxi);
        int right = solve(root->right, maxi);

        maxi = max(left+right, maxi);
        return max(left,right)+1;
    }
};
