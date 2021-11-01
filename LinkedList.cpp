#include <iostream>

using namespace std;

class Node {
  public:
  int data; //Data to store (could be int,string,object etc)
  Node * nextElement; //Pointer to next element

  Node() {
    //Constructor to initialize nextElement of newlyCreated Node
    nextElement = nullptr;
  }
};

class LinkedList {
  private:
    Node * head;
  public:

  LinkedList();
  Node * getHead();
  bool isEmpty();
  bool printList();
  void insertAtHead(int value);
  string elements();
  void insertAtTail(int value);
};

LinkedList::LinkedList() {
  head = nullptr;
}

Node * LinkedList::getHead() {
  return head;
}

bool LinkedList::isEmpty() {
  if (head == nullptr) //Check whether the head points to null
    return true;
  else
    return false;
}

bool LinkedList::printList() {
  if (isEmpty()) {
    cout << "List is Empty!";
    return false;
  }
  Node * temp = head;
  cout << "List : ";

  while (temp != nullptr) {
    cout << temp->data << "->";
    temp = temp->nextElement;
  }
  cout << "null " << endl;
  return true;
}

//Function inserts a value/new Node as the first Element of list
void LinkedList::insertAtHead(int value) {
  Node * newNode = new Node();
  newNode->data = value;
  newNode->nextElement = head; //Linking newNode to head's nextNode
  head = newNode;
  cout << value << " Inserted!";
}

string LinkedList::elements() { // this function will return all values of linked List
  string elementsList = "";
  Node * start = head;

  while (start != nullptr) {
    elementsList += std::to_string(start->data);
    elementsList += "->";
    start = start->nextElement;
  }
  elementsList += "null";
  return elementsList;
}



void LinkedList::insertAtTail(int value) {
  // Enter your code here
} 


int main(int argc, char const *argv[])
{
  
  return 0;
}