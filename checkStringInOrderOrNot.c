#include <stdio.h> // adding necessary header file

int main(void) {
    // declaring local variables
	char str[100], ch, prevChar, currChar;
	int i, inOrder;
	
    // block of code to take string input
	i = 0;
	while(1){
		ch = getchar(); // taking character wise input of string using getchar() function
		if(ch == '\n') // cheking whether user has enterd a valid character or has pressed enter key
			break;     // stop taking input when enter key is pressed
		str[i] = ch;   // storing each character in str array 
		i++;
	}
	str[i] = '\0';  // adding null terminator at the end of string

    /* block of code to check whether the string is in order or not in order */
	inOrder = 1; 
	i = 1;
	while(str[i] != '\0'){   // iterating over str array until null terminator is encountered
		prevChar = str[i-1]; // initialising prevChar
		currChar = str[i];  // initialising currChar
		
        /* checking whether the prevChar or currChar is a number or not 
           if number then breaking the loop by putting 0 in inOrder that means
           the string is Not in order otherwise continuing further
        */
		if((prevChar >= 48 && prevChar <= 57) || (currChar >= 48 && currChar <= 57)){
			inOrder = 0;
			break;
		}
		
        /* coverting both prevChar and currChar to lower case if they are in
           upper case
        */
		if(prevChar >= 65 && prevChar <= 90)
			prevChar += 32;
		if(currChar >= 65 && currChar <= 90)
			currChar += 32;
		
        /* checking the prevChar is greater than currChar or not,
           if prevChar > currChar it means the string is Not in order and it
           breaks the loop by putting 0 in inOrder
           if prevChar <= currChar it will continue further
        */
		if(prevChar > currChar){
			inOrder = 0;
			break;
		}
		
		i++; // incrementing the value of i to iterate over the entire string
	}

    /* checking for the value in inOrder and determining whether the string
       is In order or Not in order
       inOrder will finally hold either 0 or 1 based on the above conditions
       inOrder will hold 0 if the string is Not in order
       inOrder will hold 1 if the string is In order
    */	
	if(inOrder)
		printf("\nIn order\n");
	else
		printf("\nNot in order\n");
		
	return 0;
}
