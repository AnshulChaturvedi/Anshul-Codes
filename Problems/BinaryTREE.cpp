#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root){
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter the data for left node: " << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter the data for right node: " << endl;
    root -> right = buildTree(root -> right);
    return root;
    
}

void levelOrderTravesel(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

// LRR
void inOrder(node* root){
    if(root == NULL){
        return;
    }
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

// RLR
void preOrder(node* root){
    if(root == NULL){
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

// LRR
void postOrder(node* root){
    if(root == NULL){
        return;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}

void buildleveltreversel(node* &root){
    queue<node*> q;
    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter data for left node for: " << temp -> data << endl;
        int leftData;
        cin >> leftData;
        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp -> left);
        }
        cout << "Enter data for right node for: " << temp -> data << endl;
        int rightData;
        cin >> rightData;
        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }
    }
}

int main() {
    
    node* root = NULL;
    // root = buildTree(root);

    buildleveltreversel(root);

    levelOrderTravesel(root);
    // data 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // inOrder(root);
    // preOrder(root);
    // postOrder(root);
    // 2 3 16 1 -1 -1 2 -1 -1 5 -1 -1 17 2 -1 -1 -1 

}