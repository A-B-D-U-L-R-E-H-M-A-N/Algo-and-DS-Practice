#include <iostream>

using namespace std;


int * removeEven( int *& Arr, int size ) {
  
  int *tmpArray = new int[size]; // declaring a new temporary array in the heap.
  int tmpArrayPtr = 0; // Setting this variable to index through the Array
  
  for(int i=0;i<size;i++){
    if(Arr[i]%2!=0){ // if the element is odd
      tmpArray[tmpArrayPtr] = Arr[i]; // add the element to this array
      tmpArrayPtr++; // increasing the index
    }
  
  }
  delete [] Arr; // Deleting the array pointed to by arr
  Arr = new int[tmpArrayPtr]; // creating a new array in the heap of the required size

// Populating Arr array using the tmp array
  for(int i=0;i<tmpArrayPtr;i++){
    Arr[i] = tmpArray[i];
  }
  delete [] tmpArray; // deleting the tmparray
  return Arr;
}

int main(int argc, char const *argv[])
{
  
  int n = 10;
  int *myArray = new int[n];
  
  for(int i=0;i<n;i++){
    myArray[i] = i;
  }
// myArray would be {0,1,2,3,4,5,6,7,8,9}

  cout << "Printing myArray initial: " << endl;
  for(int i=0;i<n;i++){
    cout << myArray[i] << " ";
  }
  cout << endl;

  cout << "Printing myArray after the removal of "

  return 0;
}