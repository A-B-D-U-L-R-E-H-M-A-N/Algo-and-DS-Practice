#include <iostream>

using namespace std;

class Node {
  public:
    int value;
    Node * leftChild;
    Node * rightChild;
    Node();
    Node(int val);
};

class BinarySearchTree {
  private:
    Node * root;
  public:
    BinarySearchTree();
    BinarySearchTree(int rootValue);
    Node * getRoot();
    void insertBSTIter(int val);
    Node * insertRecur(Node * currentNode, int val);
    void insertBST(int value);
};


Node::Node() {
  value = 0;
  leftChild = NULL;
  rightChild = NULL;
}

Node::Node(int val) {
  value = val;
  leftChild = NULL;
  rightChild = NULL;
}

BinarySearchTree::BinarySearchTree() {
  root = NULL;
}

BinarySearchTree::BinarySearchTree(int rootValue) {
  root = new Node(rootValue);
}

Node * BinarySearchTree::getRoot() {
  return root;
}


void BinarySearchTree::insertBSTIter(int val) {
  if (getRoot() == NULL) {
    root = new Node(val);
    return;
  }

  Node * currentNode = root;
  Node * parent;
  
  while (currentNode) {
    parent = currentNode; 
    if (val < currentNode -> value) {
      
      currentNode = currentNode -> leftChild;
    } else {

      currentNode = currentNode -> rightChild;
    }
  }
  if (val < parent -> value) {
    parent -> leftChild = new Node(val);
  } else {
    parent -> rightChild = new Node(val);
  }

}

//Adding the recursive insert function
Node * BinarySearchTree::insertRecur(Node * currentNode, int val) {
  if (currentNode == NULL) {
    return new Node(val);
  } else if (currentNode -> value > val) {

    currentNode -> leftChild = insertRecur(currentNode -> leftChild, val);

  } else {
    currentNode -> rightChild = insertRecur(currentNode -> rightChild, val);
  }

  return currentNode;

}

void BinarySearchTree::insertBST(int value) {
  if (getRoot() == NULL) {
    root = new Node(value);
    return;
  }
  insertRecur(this -> getRoot(), value);
}

int main() {
  BinarySearchTree BST(13);
  cout << "The root value of the Binary Search Tree is " << BST.getRoot() -> value << endl;
  return 0;
}