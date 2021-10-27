void reArrange(int arr[], int size) {
  // A swap function is prepended. Use it like swap(arg1,arg2)
  // Write your code here
  int forwardPointer, backPointer;
  forwardPointer = 0;
  backPointer = size-1;
  while(forwardPointer < backPointer){
    while(arr[forwardPointer] < 0 && forwardPointer < size){
      forwardPointer++;
    }
    while(arr[backPointer] >= 0 && backPointer >= 0){
      backPointer--;
    }
    if(forwardPointer < backPointer)
    swap(arr[forwardPointer], arr[backPointer]);
  }

}