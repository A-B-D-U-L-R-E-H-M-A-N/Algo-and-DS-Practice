int * findProduct(int arr[], int size)  
  { 
    int n = size;
    int i, temp = 1; 
    int * product = new int[n];  // Allocate memory for the product array 
  
    // temp contains product of elements on left side excluding arr[i]
    for (i = 0; i < n; i++)  
    { 
      product[i] = temp; 
      temp *= arr[i];   
    } 
  
    temp = 1;  // Initialize temp to 1 for product on right side 

    // temp contains product of elements on right side excluding arr[i]
    for (i = n - 1; i >= 0; i--)  
    { 
      product[i] *= temp; 
      temp *= arr[i]; 
    } 
    return product; 
} 