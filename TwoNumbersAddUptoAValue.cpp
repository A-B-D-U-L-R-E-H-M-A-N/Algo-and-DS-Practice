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