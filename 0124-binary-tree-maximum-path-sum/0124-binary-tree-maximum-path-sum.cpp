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
private:
    int rec(TreeNode* root,int &maxi){
        if(root == NULL) return 0;
        int lh = rec(root->left,maxi);
        int rh = rec(root->right,maxi);
        int val = max(root->val,max(lh+root->val,rh+root->val));
        maxi = max(maxi,max(val,lh+rh+root->val));
        return val;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL)
            return root->val;
        
        int maxi= INT_MIN;
        int value = rec(root,maxi);
        return maxi;
    }
};