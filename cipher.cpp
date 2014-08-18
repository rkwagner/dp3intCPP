/*
 *Author: Ryan Wagner
 *Description: C++ Program that encodes/decodes using an alphabet
 *             substitution cipher.
 *Input:       Text to encode/decode.
 *Output:      Text encoded and then reassembled.
 */

#include<stdio.h>
#include<string>

//Function prototypes
int encKey(char a);
int decKey(int a);
//End function prototypes

int main(void){
  char abcKey[] = "QWERTYUIOPASDFGHJKLZXCVBNM ~!@#$%^&*()_+-=1029384\"756<>,./?;:'[{]}\\|`qwertyuioplkjhgfdsazxcvbnm";
  (void)printf("Strlen: %d\nEnter a string to encode: ", (int)strlen(abcKey));
  char trans[160],newString[160];
  fgets(trans, sizeof trans, stdin);
  int i;
  for(i=0;i<strlen(trans);i++){
    newString[i]=abcKey[encKey(trans[i])];
  }
  (void)printf("Encoded sequence: %s\n", newString);
  for(i=0;i<(strlen(newString));i++){
    newString[i]=decKey((strchr(abcKey,newString[i])-abcKey));
  }
  (void)printf("Decoded sequence: %s\n", newString);
}//End main function.

//Encodes input text.
int encKey(char a){
  return 126-a;
}//End encoding function.

//Decodes input text.
int decKey(int a){
  return 126-a;
}//End decoding function.
