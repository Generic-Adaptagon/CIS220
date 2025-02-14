// Ivan Escarciga
// Chpt3 PA

# include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 25
#define MAX_NUM 1000
/*

*/

//Write a program named bubbleSort based on the Pseudo code above. 


/*initilizations*/
void printArray (int sorted[], int ran[]) ;
int* randNumberGen (int blank[]) ;
int* BubbleSort(int Array[], int n);
int* copyArray (int output[], int input[]);



int main () {
	
int randNumbers[MAX] = {0};
int sortedArray[MAX] = {0};
srand(time(NULL));
int n = MAX;

	/*generates the random array of numbers*/
	randNumberGen(randNumbers);

	/*coppies array fro printing later*/
	copyArray(sortedArray, randNumbers);

	/*Sorts array*/
	BubbleSort(randNumbers, n);

	/*Prints sorted array*/
	printArray(randNumbers, sortedArray);
	return 1;
}// MAIN


int* copyArray (int output[], int input[]) {
	int count = 0;
	for (count = 0; count < MAX; count++) {
		output[count] = input[count];		
	}
	
	return output;
}

int* BubbleSort(int Array[], int n){
	int count = 0;
	int count1 = 0;
	int temp = 0;

	
     for (count = 0; count <= n - 2; count++){
          for (count1 = 0; count1 <= n - 2; count1 ++) {
               if (Array[ count1 ] > Array[ count1 +1]) {
                 /*Swap*/
					temp = Array[ count1]; 
					Array[count1] = Array[ count1 +1];
					Array[ count1 +1] = temp;
               }
          }
     }
	 
	 return Array;
}//bubble
int* randNumberGen (int blank[]) {
	int count = 0; 
	
	/*loops through each element and assigns it a number*/
	for (count = 0; count < MAX; count++) {
		
		/*sets array element to a number between 0 and MAX_NUM*/
		blank[count] = rand() % (MAX_NUM +1);
	}//for
	
	return blank;
	
}// randgen

void printArray (int sorted[], int ran[]) {
	
	int count = 0; // for counting
	
	/*Prints title and random numbers*/
	printf("Random numbers: ");
		/*loops trough all numbers*/
	for (count = 0; count < MAX; count++) {
		printf("%d ", ran[count]);
	}
	printf("\n");
	
	/*Prints title and sorted numebrs*/
	printf("Sorted numbers: ");
	/*loops trough all numbers*/
	for (count = 0; count < MAX; count++) {
		printf("%d ", sorted[count]);
	}
	printf("\n");
	
}// print