int findSecondMaximum(int arr[], int size) {
    int secondmax = INT_MIN;
    // Write your code here
    int max = arr[0];
    for(int i=0;i<size;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    for(int i=0;i<size;i++){
        if(arr[i] > secondmax && arr[i]!= max){
            secondmax = arr[i];
        }
    }
    return secondmax;
}