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
        if(root == NULL) return;
        traversal(root->left,inOrder);
        inOrder.push_back(root->val);
        traversal(root->right,inOrder);
    }

    TreeNode* createTree(int s,int e,vector<int> &inOrder){
        if(s > e){
            return NULL;
        }
        int mid = (s + e)/2;
        TreeNode* root = new TreeNode(inOrder[mid]);
        root->left = createTree(s,mid-1,inOrder);
        root->right = createTree(mid+1,e,inOrder);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inOrder;
        traversal(root,inOrder);
        
        return createTree(0,inOrder.size()-1,inOrder);
    }
};