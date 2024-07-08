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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            bool taken = false;
            for(int i=0;i<k;i++){
                auto node = q.front();
                q.pop();
                if(taken == false){
                    ans.push_back(node->val);
                    taken = true;
                }
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
        }
        return ans;
    }
};