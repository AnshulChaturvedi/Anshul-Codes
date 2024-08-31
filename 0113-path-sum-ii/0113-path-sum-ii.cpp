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
    bool isLeaf(TreeNode *root){
        return root->left == NULL && root->right == NULL;
    }

    void solve(TreeNode* root,int currSum,int target,vector<int> res,vector<vector<int>> &ans){
        if(isLeaf(root)){
            currSum += root->val;
            if(currSum == target){
                res.push_back(root->val);
                ans.push_back(res);
            }
            return;
        }
        currSum += root->val;
        res.push_back(root->val);
        if(root->left){
            solve(root->left,currSum,target,res,ans);
        }
        if(root->right){
            solve(root->right,currSum,target,res,ans);
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;

        if(!root) return ans;

        vector<int> res;
        solve(root,0,target,res,ans);
        return ans;
    }
};