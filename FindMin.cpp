// Function to return minimum from an unsorted array.



//Returns minimum value from given Array 
int findMinimum(int arr[], int size) {
	int minimum = arr[0];
    // Write your code here
	for(int i=0;i<size;i++){
		if(arr[i]< minimum){
			minimum = arr[i];
		}
	}
	return minimum;
}