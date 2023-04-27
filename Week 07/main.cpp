#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if(root->left!=nullptr)
        traverseInOrder(root->left);
    cout<<root->key<<" ";
    if(root->right!=nullptr)
        traverseInOrder(root->right);
}

// Insert a node
    struct node *insertNode(struct node *node, int key) {

        if (node == nullptr) {
            struct node* newNode = new struct node;
            newNode->key = key;
            newNode->left =nullptr;
            newNode->right =nullptr;
            return newNode;
        }

        if (key < node->key) {
            node->left = insertNode(node->left, key);
        }
        else if (key > node->key) {
            node->right = insertNode(node->right, key);
        }

        return node;
    }

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == nullptr) {
        return root;
    }
    else{
        if (root->key > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->key < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->key == key){
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                root = nullptr;
                return root;
            }
            else if (root->left == nullptr) {
                node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                node *temp = root->left;
                delete root;
                return temp;
            }
            node *node = root->right;
            while (node->left != nullptr)
                node = node->left;
            root->key = node->key;
            root->right = deleteNode(root->right, node->key);
        }
        return root;
    }
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
