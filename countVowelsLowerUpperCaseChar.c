#include <stdio.h>

int main() {

  char line[1000], character;
  int vowels, lowercase, uppercase;

  // initialize all variables to 0
  vowels = lowercase = uppercase  = 0;

  // get full line of string input
  printf("Enter a line of string: ");
  fgets(line, sizeof(line), stdin);

  // loop through each character of the string
  for (int i = 0; line[i] != '\0'; ++i) {

    // convert character to lowercase
    character = line[i];

    // check if the character is a vowel
    if (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u') {
    	vowels++; // increment value of vowels by 1
    }

    // check if the character is an uppercase character
    if (line[i] >= 'A' && line[i] <= 'Z'){
        uppercase++; // increment value of uppercase by 1
    }
    
    // check if the character is an uppercase character
    if (line[i] >= 'a' && line[i] <= 'z'){
        lowercase++; // increment value of lowercase by 1
    }
  }

  printf("\nNumber of Vowels: %d", vowels);
  printf("\nNumber of Lowercase character: %d", lowercase);
  printf("\nNumber of Uppercase character: %d\n", uppercase);

  return 0;
}
