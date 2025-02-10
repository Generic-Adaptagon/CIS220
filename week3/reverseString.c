// Ivan Escarciga
//Chpt2 PA
/*Thank you for you help with this. It took me a long time to understand what is happening.
Thinking recursivly is crazy hard for me.*/
#include <stdio.h> 
#include <string.h>

char* ReverseString(char* stringToReverse) {

	char* newArray;
	int count = 0;
	int i = 0;
	
	/*Gathers the number of the characters*/
	count = strlen(stringToReverse);	
	
	/*at count == 1, the string concists of only the last 
	character so no need to contiune the function calls*/
	if (count == 1){	
		return stringToReverse;
	} else {


		/*points to the first character in the aray, then passes in the 
		Sub String by incrementing the String value by one.*/
		newArray = ReverseString(stringToReverse + 1); 
		
		/*Takes the first character of the sub string and 
		sets it in reverse order in the new string*/
		newArray[count - 1] = stringToReverse[0]; 
																						
		/*places '\0' at then end of any/all reversed string*/
		newArray[count] = '\0';
																						
		return newArray;
	}
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
