#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {

  if(root != NULL){
    traverseInOrder(root->left);
    cout<<root->key<<" ";
    traverseInOrder(root->right);
  }

}

struct node *new_node(int key){
  struct node *new_Node = new struct node;
  new_Node->key = key;
  new_Node->left = NULL;
  new_Node->right = NULL;
  return new_Node;
}

// Insert a node
struct node *insertNode(struct node *node, int key) {

  if(node != NULL){
    if(key <= node->key){
      node->left = insertNode(node->left, key);
    }
    else{
      node->right = insertNode(node->right, key);
    }
    return node;
  }
  
  return new_node(key);

}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if(root == NULL){
    return root;
  }
  else if(root->key < key){
    root->right = deleteNode(root->right, key);
  }
  else if(root->key > key){
    root->left = deleteNode(root->left, key);
  }
  else{ 
    if(root->left == NULL){
      struct node *temp = root->right;
      delete root;
      return temp;
    }
    else if(root->right == NULL){
      struct node *temp = root->left;
      delete root;
      return temp;
    }
    else{
      struct node *temp = root->right;

      while(temp->left != NULL){
        temp = temp->left;
      }
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
    }
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
