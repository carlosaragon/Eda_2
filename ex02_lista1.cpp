#include <iostream>

typedef struct Node {
    int information;
    struct Node * left;
    struct Node * right;
} node;

node * initiateNode(int content) {
  node * newNode;
  newNode = new node;
  newNode->information = content;
  newNode->right = NULL;
  newNode->left = NULL;
  return newNode;
}

node * increaseBinaryTree(node * root, int content){
  if (!root)
     return initiateNode(content);
  if (root->information > content)
    root->left = increaseBinaryTree(root->left, content);
  else
    root->right = increaseBinaryTree(root->right, content);
  return root;
}

void inOrderPrint(node * root) {
  if(root){
    inOrderPrint(root->left);
    std::cout << root->information << '\n';
    inOrderPrint(root->right);
  }
}

void preOrderPrint(node * root) {
  if(root){
    std::cout << root->information << '\n';
    preOrderPrint(root->left);
    preOrderPrint(root->right);
  }
}

void postOrderPrint(node * root) {
  if(root){
    postOrderPrint(root->right);
    std::cout << root->information << '\n';
    postOrderPrint(root->left);
  }
}


int  main() {
  int treeSize;
  std::cin >> treeSize;
  node * root;
  root = NULL;
  for (size_t i = 0; i < treeSize; i++) {
    int content;
    std::cin >> content;
    root = increaseBinaryTree(root, content);
  }
  inOrderPrint(root);
  preOrderPrint(root);
  postOrderPrint(root);

  return 0;
}
