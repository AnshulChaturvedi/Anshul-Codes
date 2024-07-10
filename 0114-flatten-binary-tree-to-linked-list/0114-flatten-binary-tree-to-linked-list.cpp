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
    void order(TreeNode* root,vector<int> &pre){
        if(!root) return;
        pre.push_back(root->val);
        order(root->left,pre);
        order(root->right,pre);
    }

    void flatten(TreeNode* root) {
        vector<int> pre;
        order(root,pre);
        // ListNode* head = new ListNode(pre[0]);
        // ListNode* curr = head;
        // for(int i=1;i<pre.size();i++){
        //     ListNode* nextNode = new ListNode(pre[i]);
        //     curr->next = nextNode;
        //     curr = nextNode;
        // }

        for(int i=1;i<pre.size();i++){
            root->right = new TreeNode(pre[i]);
            root->left = NULL;
            root = root->right;
        }
    }
};