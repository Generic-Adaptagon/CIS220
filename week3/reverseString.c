#include <stdio.h> 
#include <string.h>

char* ReverseString(char* stringToReverse) {
	/* TODO: Complete recursive ReverseString() function here. */

	
	//char* charPointer;
	char returnString[20] = "";
	char subString[20] = "";
	int count = 0;
	int i = 0;
	//charPointer = &stringToReverse[0];

     
	/*displays count to verify string contents*/
	count = strlen(stringToReverse);
	printf("Debug:  count = %4d   String: %4s  ", count, stringToReverse);
	
	
	/*gets count and*/
	if (count != 0) {
	returnString[count - 1] = stringToReverse[0];
	}//if
	
	/*Makes substring*/
	    	
	for (i = 1; i < count; i++){
	subString[i-1] = stringToReverse[i];
	}//for

	
	/*displays substring for verification*/
	printf("Sub String:%s   ", subString);
	
	
	/*this is the problem child*/
		//this first string displays "ahhh" verifying it works, 
		//but then the next if statement it crashes
	if(stringToReverse[0] == '\0') {printf("AHHH\n");} // adding this line again does not segfault
		//this is where it crashes, expected return in main:yay\n Reversed: test
	if(stringToReverse[0] == '\0') {printf("yay\n"); return "test";}
	
	printf("itterated\n");   
	/*Testing in progress; I want to return reverseString, but it gives me trouble*/
	strcat(ReverseString(subString) , &stringToReverse[count-1]);
		//function			//last char
		

	printf("end");
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
