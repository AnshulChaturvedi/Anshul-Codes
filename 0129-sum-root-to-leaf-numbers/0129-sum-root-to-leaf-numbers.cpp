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
    void rec(TreeNode* root,string str,vector<string> &ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            str.append(to_string(root->val));
            ans.push_back(str);
            return;
        }
        str.append(to_string(root->val));
        rec(root->left,str,ans);
        rec(root->right,str,ans);
    }
public:
    int sumNumbers(TreeNode* root) {
        // root to leaf numbers add in string then stoi and add them all
        string str = "";
        vector<string> ans;
        int sum = 0;
        
        rec(root,str,ans);
        
        for(int i=0;i<ans.size();i++){
            sum += stoi(ans[i]);
        }
        return sum;
    }
};