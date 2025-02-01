// Ivan Escarciga
// Chpt2 PA

#include <stdio.h>
#include <string.h>

char* ReverseString(char* stringToReverse) {
	/* TODO: Complete recursive ReverseString() function here. */
	
	int front = 0; // used for front tracking
	int back = 0 ; // used for back tracking
	char temp = 'z'; // used for swapping
	int stringLength = 0;// used for string length
	
	stringLength = strlen(stringToReverse);
	front = 0; //initilaizing vars
	back = stringLength -1;

	for (int count = 0; count <= stringLength; count++) {
		
		//swap
		temp = stringToReverse[front];
		printf("temp = %c\n", temp);
		stringToReverse[front] = stringToReverse[back];
		printf("front = %c\n", stringToReverse[front] );
		stringToReverse[back] = temp;
			
		if (front == back + 1) {printf("nooo");break;}

		if (front == back) {break;}
		front++;
		back--;
		printf("iterated\n");
	} // count for
	
	printf("%d\n", stringLength);
	
	return stringToReverse;
	
	
	
	
	/*
	int stringLength = 0; // used to store strgin length
	int count = 0; //a counting Var
	int reverseCount = 0; //for counting the opposite way of count	
	char reversedString[50] = ""; // used for transferring string
	char* Return;
	
	//get string lenght
	stringLength = strlen(stringToReverse); // this gets the array length
	printf("array length = %d\n", stringLength);
	
	

	int testCount = 0;
	while (stringToReverse[testCount] != '\0'){
	testCount ++;
	}
	printf("arraly Length, manual = %d\n", testCount);
		
	reverseCount = stringLength; //initalize reverse count	
	for (count = 0; count < stringLength; count++) {
		reversedString[count] = stringToReverse[reverseCount];
		reverseCount--; //iterating through passed in string backwards	
	}//for count
	
	Return = reversedString;
	//assign OG string as walking backwards as itterating backwards through the string until 0

	*/
	//return "owo";
}

int main(void) {
	char inStr[50];
	char* resultStr;
   
	printf("Enter the string to be reversed: ");
	fgets(inStr, 20, stdin);
	strtok(inStr, "\n");  // Remove newline character from input.
	
	resultStr = ReverseString(inStr);
	
	printf("Reversed: %s\n", resultStr);

   return 0;
}
