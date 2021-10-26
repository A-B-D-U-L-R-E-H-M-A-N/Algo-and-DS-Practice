void rightRotate(int arr[], int size) {
  // Write your code here  
  int rightMost;
  rightMost = arr[size-1];
  for(int i=size-2;i>=0;i--){
    arr[i+1] = arr[i];
  }
  arr[0] = rightMost;
}