#include <iostream>
#include <ostream>

using namespace std;

class TreeNode {
public:
  TreeNode(int val);
  TreeNode *left;
  TreeNode *right;
  int val;
};

TreeNode::TreeNode(int val) {
  this->val = val;
  left = nullptr;
  right = nullptr;
}

// Forward declaration so Tree can grant friendship
class TreeTraversal;

class Tree {
public:
  Tree();
  ~Tree();
  void insert(int val);

  friend class TreeTraversal;

private:
  TreeNode *root;
  void destroy(TreeNode *node);
};

Tree::Tree() { root = nullptr; }

Tree::~Tree() { destroy(root); }

void Tree::destroy(TreeNode *node) {
  if (node != nullptr) {
    destroy(node->left);
    destroy(node->right);
    delete node;
  }
}

void Tree::insert(int val) {
  TreeNode *newNode = new TreeNode(val);
  if (root == nullptr) {
    root = newNode;
  } else {
    TreeNode *current = root;
    while (current != nullptr) {
      if (val < current->val) {
        if (current->left == nullptr) {
          current->left = newNode;
          break;
        }
        current = current->left;
      } else {
        if (current->right == nullptr) {
          current->right = newNode;
          break;
        }
        current = current->right;
      }
    }
  }
}

// Base class for external traversal printers
class TreeTraversal {
public:
  TreeTraversal(const Tree &t) : tree(t) {}
  virtual ~TreeTraversal() = default;

  friend ostream &operator<<(ostream &os, const TreeTraversal &traversal) {
    traversal.print(os);
    return os;
  }

protected:
  const Tree &tree;
  TreeNode *getRoot() const { return tree.root; }
  virtual void print(ostream &os) const = 0;
};

class InOrder : public TreeTraversal {
public:
  InOrder(const Tree &t) : TreeTraversal(t) {}

protected:
  void print(ostream &os) const override { traverse(os, getRoot()); }

private:
  void traverse(ostream &os, TreeNode *node) const {
    if (node != nullptr) {
      traverse(os, node->left);
      os << node->val << " ";
      traverse(os, node->right);
    }
  }
};

class PreOrder : public TreeTraversal {
public:
  PreOrder(const Tree &t) : TreeTraversal(t) {}

protected:
  void print(ostream &os) const override { traverse(os, getRoot()); }

private:
  void traverse(ostream &os, TreeNode *node) const {
    if (node != nullptr) {
      os << node->val << " ";
      traverse(os, node->left);
      traverse(os, node->right);
    }
  }
};

class PostOrder : public TreeTraversal {
public:
  PostOrder(const Tree &t) : TreeTraversal(t) {}

protected:
  void print(ostream &os) const override { traverse(os, getRoot()); }

private:
  void traverse(ostream &os, TreeNode *node) const {
    if (node != nullptr) {
      traverse(os, node->left);
      traverse(os, node->right);
      os << node->val << " ";
    }
  }
};

int main() {
  Tree tree;
  tree.insert(3);
  tree.insert(5);
  tree.insert(2);

  cout << "Inorder: " << InOrder(tree) << endl;
  cout << "Preorder: " << PreOrder(tree) << endl;
  cout << "Postorder: " << PostOrder(tree) << endl;

  return 0;
}