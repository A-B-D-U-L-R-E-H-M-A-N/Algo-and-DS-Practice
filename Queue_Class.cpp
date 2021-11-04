
#include "Stack_Class.cpp"
#include <iostream>
#include <cassert>


using namespace std;


class myQueue {
  private:
  int * queueArr;
  int capacity;
  int numElements;
  int front;
  int back;
  public:
  myQueue(int size);
  bool isEmpty();
  int getFront();
  void enqueue(int value);
  int dequeue();
  int getSize();
  void showqueue();
  myQueue reverseK(myQueue queue, int k);
};



myQueue::myQueue(int size) {
  capacity = size;
  queueArr = new int[size];
  assert(queueArr != NULL); 
  numElements = 0;
  front = 0;
  back = -1;

}

bool myQueue::isEmpty() {
  return (numElements == 0);
}

int myQueue::getFront() {
  if (isEmpty()) {
    cout << "Queue Empty" << endl;
    return -1;
  } else
    return queueArr[front];
}

void myQueue::enqueue(int value) {
  if (numElements == capacity) {
    cout << "Queue Full" << endl;
    return;
  }

  if (back == capacity - 1)
    back = -1;

  queueArr[++back] = value;
  numElements++;
}

int myQueue::dequeue() {
  if (isEmpty()) {
    cout << "Queue Empty" << endl;
    return -1;
  }
  int tmp = queueArr[front++];

  if (front == capacity)
    front = 0;
  numElements--;
  return tmp;

}
int myQueue::getSize() {
  return numElements;
}

void myQueue::showqueue() {
  int i = front;
  int count = 0;
  while (count != numElements) {
    cout << '\t' << queueArr[i%capacity];
    i++;
    count++;
  }
  cout << '\n';
}

myQueue myQueue::reverseK(myQueue queue, int k) {
    myQueue *q = new myQueue(queue.getSize());
    myStack *tmp = new myStack(k);
    int holder;
    for(int i=0;i<k;i++){
      if(! queue.isEmpty()){
      holder = queue.dequeue();
      tmp -> push(holder);
    }    
    }
    int sizequeue = queue.getSize();
    for(int i=0;i<k;i++){
      q -> enqueue(tmp -> pop());
    }
    for(int i=0;i<sizequeue;i++){
      q -> enqueue(queue.dequeue());
    }
    return *q;
}


int main() {

  myQueue queue(5);
  queue.enqueue(2);
  queue.enqueue(4);
  queue.enqueue(6);
  queue.enqueue(8);
  queue.enqueue(10);
  queue.showqueue();
  cout << "Adding 6th element to a queue with capacity equal to 5: " << endl;
  queue.enqueue(12);

  queue.showqueue();
  queue.dequeue();
  queue.dequeue();
  queue.showqueue();
  cout << "The size of queue is: " << queue.getSize() << endl;
  queue.enqueue(14);
  queue.enqueue(16);
  queue.showqueue();
  cout << "The size of queue is: " << queue.getSize() << endl;

  return 0;
}
