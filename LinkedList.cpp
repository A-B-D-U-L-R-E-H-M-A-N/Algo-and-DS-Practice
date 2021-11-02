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
  bool search(int value);
  bool deleteAtHead();
  bool Delete(int value);
  int length();
  string reverse();
  bool detectLoop();
  int findMidSlow();
  int findMidFast();
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
  Node * tmpHead = getHead();
  if(tmpHead == NULL){
    insertAtHead(value);
  }else{
  while(tmpHead -> nextElement){
    tmpHead = tmpHead -> nextElement;
  }
  Node * newnode = new Node();
  newnode -> nextElement = NULL;
  newnode -> data = value;
  tmpHead ->nextElement = newnode;
  }
  
} 

bool LinkedList::search(int value){ 
  // Write your code here
  Node * tmpPointer = getHead();
  if(isEmpty()){
    return false;
  }else{
    do{
      if(tmpPointer->data == value){
        return true;
      }else{
        tmpPointer = tmpPointer -> nextElement;
      }
    }while(tmpPointer);
  }
  return false;
}

bool LinkedList::deleteAtHead() {
  if (isEmpty()) { // check if lis is empty
    cout << "List is Empty" << endl;
    return false;
  }
  Node * currentNode = head; 
  head = head->nextElement; 
  
  delete currentNode;
  return true;
}

bool LinkedList::Delete(int value){
  Node *tmpPointer = getHead();
  if(isEmpty()){
    return false;
  }else if(tmpPointer -> data == value){
    deleteAtHead();
    return true;
  }else{
    while(tmpPointer->nextElement){
      if(tmpPointer->nextElement->data==value){
        Node *tmpNode = tmpPointer -> nextElement;
        tmpPointer -> nextElement = tmpNode -> nextElement;
        delete(tmpNode);
        return true;
      }else{
        tmpPointer = tmpPointer->nextElement;
      }
    }
  }
  return false;
}


int LinkedList::length(){
  int count = 0;
  Node *tmpPointer = getHead();
  while(tmpPointer){
    count++;
    tmpPointer = tmpPointer->nextElement;
  }
  return count;
}

string LinkedList::reverse() {
    // Write your code here
  Node *p = NULL;
  Node *q = getHead();
  while(head->nextElement){
    head = head -> nextElement;
    q -> nextElement = p;
    p = q;
    q = head;
  }
  head -> nextElement = p;
return elements();
}

bool LinkedList::detectLoop(){
  Node *first = head;
  Node *second = head;

  while(second->nextElement){
      second = second ->nextElement;
    if(second -> nextElement){
      second = second -> nextElement;
      if(first == second){
        return true;
      }
      if(first -> nextElement){
      first = first -> nextElement;
      if(first == second){
        return true;
      }
      }
    }
  }

  return false;
}


int LinkedList::findMidSlow() {
  int mid;
  if(length()%2==0){
    mid = length()/2;
  }else{
    mid = (length()/2) + 1;
  }
  Node *tmp = head;
  for(int i=0;i<mid-1;i++){
    tmp = tmp ->nextElement;
  }
  return tmp -> data;
  return 0;
}

int LinkedList::findMidFast(){
  Node *first;
  Node *second;
  first = second = head;
  while(second -> nextElement){
    second = second -> nextElement;
    if(second -> nextElement){
      second = second ->nextElement;
      first = first -> nextElement;
    }
  }
  return first -> data;
}

int main(int argc, char const *argv[])
{
  LinkedList myList;
  for (int i = 0; i < 10; ++i)
  {
    myList.insertAtHead(i);
  }

  myList.insertAtTail(2010);
  myList.insertAtTail(2011);
  cout << "/n" << "Finding 2010 " << myList.search(2010) << endl;
  myList.Delete(2011);
  cout << endl << " " << myList.length();


  myList.printList();

  cout << myList.reverse();
  
  return 0;
}