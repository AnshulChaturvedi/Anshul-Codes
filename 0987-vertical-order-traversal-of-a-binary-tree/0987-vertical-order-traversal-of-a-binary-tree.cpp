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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        map<int,map<int,multiset<int>>> mpp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        // ({node,{vertical,level}})
        q.push({root,{0,0}});
        while(!q.empty()){
            auto node = q.front().first;
            int lvl = q.front().second.second;
            int ver = q.front().second.first;
            q.pop();
            if(node->left){
                q.push({node->left,{ver-1,lvl+1}});
            }
            if(node->right){
                q.push({node->right,{ver+1,lvl+1}});
            }
            mpp[ver][lvl].insert(node->val);
        }
        for(auto &p : mpp){
            vector<int> res;
            for(auto &q : p.second){
                res.insert(res.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(res);
        }
        return ans;
    }
};