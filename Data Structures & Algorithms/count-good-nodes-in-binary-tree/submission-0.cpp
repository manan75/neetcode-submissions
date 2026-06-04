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
int ctr =0;
    int goodNodes(TreeNode* root) {
        //keep some max counter

        
        int curr =INT_MIN;

     solve(root,curr);
        return ctr;
    }

   void solve(TreeNode * root, int curr){
        if(root==nullptr){
            return ;
        }
         curr = max(curr,root->val);
         solve(root->left,curr);
         solve(root->right, curr);
        if(curr<=root->val){
            ctr++;
        }
       


    }
};
