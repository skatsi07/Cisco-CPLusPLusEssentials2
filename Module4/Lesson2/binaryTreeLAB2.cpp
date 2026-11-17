#include <ios>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

using namespace std;

class TreeNode{
    public:
        TreeNode(int val);
        TreeNode *left;
        TreeNode *right;
        int val;
};

TreeNode::TreeNode(int val){
    this->val = val;
    left = nullptr;
    right = nullptr;
}

class Tree{
    public:
        Tree();
        void insert(int val);
        void inorder(TreeNode* root);
        void preOrder(TreeNode* root);
        void postOrder(TreeNode* root);
        friend ostream& operator<<(ostream& os, Tree& tree);
        private:
            TreeNode* root;
};

Tree::Tree(){
    root = nullptr;
}

void Tree::insert(int val){
    TreeNode* newNode = new TreeNode(val);
    if(root == nullptr){
        root = newNode;
    }
    else{
        TreeNode* current = root;
        while(current != nullptr){
            //if val less go left
            if(val < current->val){
                if(current->left == nullptr){
                    current->left = newNode;
                    break;
                }
                current = current->left;
            }
            //go right
            else{
                if(current->right == nullptr){
                    current->right = newNode;
                    break;
                }
                current = current->right;
            }
        }
    }
}

void Tree::inorder(TreeNode* root){
    if(root != nullptr){
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

void Tree::preOrder(TreeNode* root){
    if(root != nullptr){
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void Tree::postOrder(TreeNode* root){
    if(root != nullptr){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }
}

ostream& operator<<(ostream& os, Tree& tree){
    cout << "Inorder: "; 
    tree.inorder(tree.root);
    cout << endl;
    cout << "Postorder: ";
    tree.postOrder(tree.root);
    cout << endl;
    cout << "Preorder: ";
    tree.preOrder(tree.root);
    cout << endl;
    return os;
}

int main(){

    Tree tree;
    tree.insert(3);
    tree.insert(5);
    tree.insert(2);

    cout << tree << endl;
    return 0;
}
