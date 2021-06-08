/**
 *
 * Starter file for Lab 8
 * Note: You may not change any of the parameters of the functions or typedefs.
 *		You may use a different printArray function if you wish.
 */ 

#include<stdio.h>

/**
 * Create a typedef for a  Compare Function 
 */
typedef int (*CompareFunc)(void* a, void* b);

int compare1(void *a, void *b){
	int *num1 = (int *) a;
	int *num2 = (int *) b;

	if(*num1 > *num2){
		return 1;
	}
	else if(*num1 < *num2){
		return -1;
	}
	else{
		return 0;
	}
}

int compare2(void *a, void *b){
	int *num1 = (int *) a;
	int *num2 = (int *) b;

	if(*num1 > *num2){
		return -1;
	}
	else if(*num1 < *num2){
		return 1;
	}
	else{
		return 0;
	}
	
}

int compare3(void *a, void *b){
	int *num1 = (int *) a;
	int *num2 = (int *) b;

	if(*num2 % 2 == 0){
		if(*num1 % 2 == 1){
			return 1;
		}
		else{
			if(*num1 > *num2){
				return 1;
			}
			else{
				return -1;
			}
		}
	}
	else{
		return 1;
	}
	
}

/**
 * Create a typedef for a Sort Algorithm of an array
 */
typedef void (*SortAlgorithm) (int* container, int length,  CompareFunc cf);

void bubbleSort(int* container, int length,  CompareFunc cf){
	int i = 0;
	int j = 0;
	int n = 0;
	for(i = 0; i < length; i++){
		for(j = 0; j<length - 1; j++){
			if(cf(&container[j], &container[j+1])>= 0){
				n = container[j];
				container[j] = container[j + 1];
				container[j+1] = n;
			}
		}
	}
}

void insertSort(int* container, int length,  CompareFunc cf){
	int i = 1;
	int j = 0;
	int n = 0;
	while(i < length){
		j = i;
		while(j < length && cf(&container[j-1], &container[j]) >= 0){
			n = container[j];
			container[j] = container[j - 1];
			container[j-1] = n;
			j = j - 1;
		}
		i++;
	}
	
}

/**
 * Print an array of integers with a specific length.
 */
void printArray( int* arr, int length )
{
	for(int i =0 ; i < length; i++ ) 
		printf("%d ", arr[i]);
	printf("\n");
}

/***
 * NOTE: You will implement this function, it will be used to call all sorting algorithms. 
 *      It will also output the all the information required by the output section of the lab.
 *       
 * menuSelection is the text for the menu option that was selected.
 * sorter -> is the sorting function
 * array -> is the input array given by the user
 * length-> is the length of the array
 * compare -> is a comparison function pointer.
 */
void sort( char* menuSelection, SortAlgorithm sorter, int* array, int length, CompareFunc compare);


int main(int argc, char ** argv )
{
	int i = 0;
	int size = 0;
	int choice = 0;
	printf("Size of the array: ");
	scanf("%d", &size);
	getchar();
	int arr[size];
	for(i = 0; i < size; i++){
		printf("Enter an element for the array: ");
		scanf("%d", &arr[i]);
		getchar();
	}
	printf("What method of sorting?");
	scanf("%d", &choice);
	getchar();

	if(choice == 1){
		bubbleSort(arr, size, compare1);
	}
	else if(choice == 2){
		insertSort(arr, size, compare1);
	}
	printArray(arr, size);

	return 0;
}