// code to merge two sorted arrays into a single sorted array.
#include<iostream>
using namespace std;



int * mergeArrays(int arr1[], int arr2[], int arr1Size,int arr2Size)
{
    int * arr3; // creating new array
    arr3 = new int[arr1Size + arr2Size]; //creating a new array to hold the elements

    int arr1Index = 0, arr2Index = 0;
    int arr1finished = 0, arr2finished = 0;

    for(int i=0;i<(arr1Size + arr2Size); i++){
        if(arr1[arr1Index] < arr2[arr2Index] && arr1finished==0){
            arr3[i] = arr1[arr1Index];
            
             if(arr1Index == arr1Size-1){
                arr1finished = 1;
            }

            if(arr1Index < arr1Size-1){
                arr1Index++;
            }
           
        }else if(arr2[arr2Index] <= arr1[arr1Index] && arr2finished ==0){
            arr3[i] = arr2[arr2Index];
            
            if(arr2Index == arr2Size-1){
                arr2finished = 1;
            }
            
            if(arr2Index < arr2Size-1){
                arr2Index++;
            }
            
        }else if(arr1finished==1){
            arr3[i] = arr2[arr2Index];
            arr2Index++;
        }else{
            arr3[i] = arr1[arr1Index];
            arr1Index++;
        }
    }
    return arr3; // returning array
}


int main(int argc, char const *argv[])
{
    
    return 0;
}