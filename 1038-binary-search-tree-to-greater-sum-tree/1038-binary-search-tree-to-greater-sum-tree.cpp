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
    void traversal(TreeNode* root,vector<int> &inOrder){
        if(root == NULL)
            return;
        traversal(root->left,inOrder);
        inOrder.push_back(root->val);
        traversal(root->right,inOrder);
    }
    
    void greaterTree(TreeNode* root,vector<int> &inOrder){
        if(root == NULL)
            return;

        greaterTree(root->left,inOrder);
        int nodeVal = root->val;
        int sum = 0;
        for(int i=0;i<inOrder.size();i++){
            if(inOrder[i] >= nodeVal)
                sum += inOrder[i];
        }
        root->val = sum;
        greaterTree(root->right,inOrder);
    }

    TreeNode* bstToGst(TreeNode* root) {
        
        vector<int> inOrder;
        traversal(root,inOrder);

        greaterTree(root,inOrder);

        return root;
    }
};