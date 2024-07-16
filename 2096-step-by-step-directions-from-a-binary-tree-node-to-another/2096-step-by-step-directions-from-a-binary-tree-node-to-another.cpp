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
    bool findPath(TreeNode* root,int target,string &res){
        if(root == NULL) return false;
        if(root->val == target) return true;
        res.push_back('L');
        if(findPath(root->left,target,res)==true) return true;
        res.pop_back();
        res.push_back('R');
        if(findPath(root->right,target,res) == true) return true;
        res.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootToSrc = "";
        string rootToDst = "";
        findPath(root,startValue,rootToSrc);
        findPath(root,destValue,rootToDst);
        string ans = "";
        int l = 0;
        while(l<rootToSrc.size() && l<rootToDst.size() && rootToSrc[l] == rootToDst[l]) l++;
        for(int i=0;i<rootToSrc.size()-l;i++) ans.push_back('U');
        for(int i=l;i<rootToDst.size();i++) ans.push_back(rootToDst[i]);
        return ans;
    }
};