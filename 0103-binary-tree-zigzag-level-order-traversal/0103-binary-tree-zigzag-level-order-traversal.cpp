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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        while(!q.empty()){
            int k = q.size();
            vector<int> res(k);
            for(int i=0;i<k;i++){
                auto node = q.front();
                q.pop();
                //
                int idx = (lvl&1)? k-1-i : i;
                res[idx] = node->val;
                //
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(res);
            lvl++;
        }
        return ans;
    }
};