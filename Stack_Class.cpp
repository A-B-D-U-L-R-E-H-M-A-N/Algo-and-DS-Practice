#include <iostream>
#include <cassert>

using namespace std;

class myStack {
  private:
  int * stackArr;
  int capacity;
  int numElements;
  public:
  myStack(int size);
  bool isEmpty();
  int getTop();
  bool push(int value);
  int pop();
  int getSize();
  void showStack();
};


myStack::myStack(int size) {
  capacity = size;
  stackArr = new int[size];
  assert(stackArr != NULL); 
  numElements = 0;
}

bool myStack::isEmpty() {
  return (numElements == 0);
}

int myStack::getTop() {
  return (numElements == 0 ? -1 : stackArr[numElements - 1]);
}

bool myStack::push(int value) {
  if (numElements < capacity) {
    stackArr[numElements] = value;
    numElements++;
    return true;
  } else {
    cout << "Stack Full." << endl;
    return false;
  }
}

int myStack::pop() {
  if (numElements == 0) {
    cout << "Stack Empty" << endl;
    return -1;
  } else {
    numElements--;
    return stackArr[numElements];
  }
}

int myStack::getSize() {
  return numElements;
}

void myStack::showStack() {
  int i = 0;
  while (i < numElements) {
    cout << '\t' << stackArr[numElements - 1 - i];
    i++;
  }
  cout << '\n';
}



// Two_Stacks using one array.

class twoStacks {

private:
    int size;
    int *arr;
    int top1, top2;
   
public:
    twoStacks(int n) {
        size = n;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
 
    void push1(int value) {
      if(top1 + 1 < top2 && top1 >= -1 && top1 < size-1){
        arr[top1 + 1] = value;
        top1++;
      }
    }
 
    void push2(int value) {
      if(top2 - 1 > top1 && top2 >= 1 && top2 <= size){
        arr[top2-1] = value;
        top2--;
      }
    }

    int pop1() {
      int ret;
      if(top1 >= 0){
        ret = arr[top1];
        //arr[top1] = 0;
        if(top1 > -1)
        top1--;
        return ret;
      }
      return -1;
    }

    int pop2() {
      int ret;
      if(top2 <= size -1){
        ret = arr[top2];
        //arr[top2] = 0;
        if(top2 < size)
        top2++;
        return ret;
      }
      return -1; 
    }
    void dispElements(){
      for(int i=0;i<size;i++){
        cout << arr[i] << "  ";
      }
      cout << endl;
    }
};


int main() {
  
  /*myStack s(10);
  cout << "\ns.top(): " << s.getTop();
  s.push(10);
  s.push(30);
  s.push(20);
  s.push(5);
  s.push(1);
  cout << "\nThe stack is: ";
  s.showStack();
  cout << "\ns.top(): " << s.getTop();
  cout << "\ns.pop(): " << s.pop() << endl;
  cout << "\ns.pop(): " << s.pop() << endl;
  cout << "\ns.pop(): " << s.pop() << endl;
  cout << "\ns.pop(): " << s.pop() << endl;
  s.push(23);
  s.push(57);
  s.push(17);
  s.push(29);
  s.push(6);
  s.push(7);
  s.push(12);
  s.push(19);
  cout << "\nThe stack is: ";
  s.showStack();
  cout << "\ns.pop(): " << s.pop() << endl;
  cout << "s.pop(): " << s.pop() << endl;
  cout << "The stack size is: " << s.getSize() << endl;*/

    twoStacks tS(5);
    tS.push1(11);
    tS.push1(3);
    tS.push1(7);
    tS.push2(1);
    tS.push2(9);
    tS.dispElements();


  
  cout << tS.pop1() << endl;
  cout << tS.pop2() << endl;
  cout << tS.pop2() << endl;
  cout << tS.pop2() << endl;
  cout << tS.pop1() << endl;



  return 0;
  
}