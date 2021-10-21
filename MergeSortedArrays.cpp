// code to merge two sorted arrays into a single sorted array.
#include<iostream>
using namespace std;



int * mergeArrays(int arr1[], int arr2[], int arr1Size,int arr2Size)
{
    int * arr3; // creating new array
    arr3 = new int[arr1Size + arr2Size]; //creating a new array to hold the elements

    int arr1Index = 0, arr2Index = 0;
    int arr1finished = 0, arr2finished = 0;

    // looping through the array
    for(int i=0;i<(arr1Size + arr2Size); i++){
        if(arr1[arr1Index] < arr2[arr2Index] && arr1finished==0){ // smallest element from the array if not finished.
            arr3[i] = arr1[arr1Index];
            
             if(arr1Index == arr1Size-1){
                arr1finished = 1;
            }

            if(arr1Index < arr1Size-1){
                arr1Index++;
            }
           
        }else if(arr2[arr2Index] <= arr1[arr1Index] && arr2finished ==0){ // else the element from the other element.
            arr3[i] = arr2[arr2Index];
            
            if(arr2Index == arr2Size-1){
                arr2finished = 1;
            }
            
            if(arr2Index < arr2Size-1){
                arr2Index++;
            }
            
        }else if(arr1finished==1){ // if array1 finished, copy the remaining elements from array2
            arr3[i] = arr2[arr2Index];
            arr2Index++;
        }else{ // If array2 has finished, copy all the remaining elements from array1
            arr3[i] = arr1[arr1Index]; 
            arr1Index++;
        }
    }
    return arr3; // returning array
}


int main(int argc, char const *argv[])
{
    int array1[] = {1,6,9,10,15,18, 19};
    int array2[] = {16,19,23,45,67,89};
    int *array3 = mergeArrays(array1,array2,7,6);

    cout << "The merged array: " << endl;
    for(int i=0; i<12;i++){
        cout << array3[i] << " ";
    }

    cout << endl;
    return 0;
}