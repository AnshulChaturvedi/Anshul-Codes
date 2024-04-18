class Codec {
public:

    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node == NULL){
                s.append("N,");
            }
            else{
                s.append(to_string(node->val)+",");
            }
            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        
        //string as an object
        stringstream s(data);
        
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            getline(s,str, ',');
            if(str == "N"){
                node->left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            
            getline(s,str, ',');
            if(str == "N"){
                node->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        
        return root;   
    }
};