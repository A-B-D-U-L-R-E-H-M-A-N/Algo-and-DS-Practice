#include <iostream>

using namespace std;

//Return 2 elements of arr that sum to the given value
int * findSum(int arr[], int value, int size) {
  // Sorting function is prepended as sort(arr, low, high)
  
    // Write your code here
    int value1 = 0, value2 = 0, found=0;
    
    for(int i=0;i<size;i++){
      for(int j=i+1;j<size;j++){
        if ((arr[i] + arr[j])==value){
          value1 = arr[i];
          value2 = arr[j];
          found =1;
        }
      }
    }
    if(found==1){
      int *returnarr = new int[2];
      returnarr[0] = value1;
      returnarr[1] = value2;
      return returnarr;
    }
	return arr; 
} 


int main(){

  int size = 5, value = 9;
  int arr[] = {2,4,5,7,8};
  
  if(size > 0){
    int * arr2 = findSum(arr, value, size);
    int num1 = arr2[0];
    int num2 = arr2[1];

      if((num1 + num2) != value)
        cout << "Not Found" << endl;
      else {
        cout << "Number 1 = " << num1 << endl;
        cout << "Number 2 = " << num2 << endl;
        cout << "Sum = " << num1+num2 << endl;

      }
    } else {
      cout << "Input Array is Empty!" << endl;
    }
}