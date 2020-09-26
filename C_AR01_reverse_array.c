/* 
  This program read a string from stdin and parse it as an array.
  example input:1 2 32 934 0
  ouput:0 934 32 2 1
  
  cmd compile and execution: rm a.exe & gcc C_AR01_reverse_array.c && a.exe & echo    Return code:%ERRORLEVEL%
*/

//----------USER define------------
#define DEBUG       1    // print auxiliary text or not
#define TEXT_SIZE 128    // size of input text in bytes
#define SPILTOR   " "    // a character that spilts input array, for example "10 38 21 70 43"
//------END USER define------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x, y) (x<y?x:y)
#define SWAP(t, x, y) {t tmp = x; x = y; y = tmp;} //usage: SWAP(int, a, b);


int main(){
  
  unsigned int counts=1;  // item counts in the input array
  char* text;             // input text
  char** rev_array;       // result array: in the reversed order of the input array
  char* item;             // an item in the input array
  text=calloc(TEXT_SIZE, sizeof(char));
  if(DEBUG)
    printf("Please enter an numerical array, spilted with space.\n:");
  
  //fgets(text, TEXT_SIZE-2, stdin);
  scanf("%[^\n]", text);
  
  if(DEBUG){
    printf("The text you entered:%s\n", text);
    printf("strlen(text):%d\n", strlen(text));
  }
  
  // count for how many spaces
  for(unsigned int i=0; i<TEXT_SIZE-1; i++){
    if     (text[i]==SPILTOR[0]) counts++;
    else if(text[i]=='\0')    break;
  }
  
  if(DEBUG)
    printf("Array counts:%d\n", counts);
  
  // assign size of rev_array={"10", "12", "83", "23"};
  rev_array=calloc(counts, sizeof(char*));
  item=strtok(text, (char*)SPILTOR);  //get the first item in text
  for(unsigned int i=0; i<counts; i++){
    rev_array[counts-i-1]=item;
    item=strtok(NULL, (char*)SPILTOR);
  }
  
  // print the result
  for(unsigned int i=0; i<counts; i++){
    printf("%s", rev_array[i]);
    if(i==counts-1)   printf("\n");
    else              printf(" ");

    // you cant free rev_array[i] cuz it's not assign from allocation function
  }
  free(rev_array);
  free(text);
  if(DEBUG)
    printf("\n\n\n\nProgram ended. ");
}
