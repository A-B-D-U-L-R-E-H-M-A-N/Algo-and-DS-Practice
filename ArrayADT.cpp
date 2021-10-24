#include <iostream>

using namespace std;

class ArrayADT
{
private:
	int *ArrayPtr;
	int size;  // the total size of the array.
	int length; // the number of elements currently in the array.
public:
	ArrayADT(int arraysize){		//Constructor which takes in an initial size and creates the dynamic aray of that size.
		ArrayPtr = new int[arraysize];
		size = arraysize;
		length = 0;
	}

	void Display(){  				// Displays all the elements of that array
		for(int i=0;i<length; i++){
			cout << ArrayPtr[i] << " ";
		}
	}

	void insert(int number){ 		// if capacity is full, make a new tmp array, fill it in and insert numbers. Otherwise insert numbers just as.
		if(length==size){
			int *tmpPointer = new int[size*2];
			for(int i=0;i<size;i++){
				tmpPointer[i] = ArrayPtr[i];
			}
			tmpPointer[length] = number;
			size = size*2;
			length++;

			delete []ArrayPtr;
			ArrayPtr = tmpPointer;
		}else{
			ArrayPtr[length] = number;
			length++;
		}
	}
	void insertAtIndex(int index, int value){
		
	}
};


int main(int argc, char const *argv[])
{
	ArrayADT newArray(2);
	newArray.insert(0);
	newArray.insert(1);
	newArray.insert(7);
	for(int i=0;i<1000000;i++){
		newArray.insert(i);
	}
	newArray.Display();
	
	return 0;
}