/* 
  This program read a string from stdin and parse it as an int array,
  then output the product.
  example input:1 2 32 7
  ouput:448
  
  cmd compile and execution: rm a.exe & gcc C_OT61_product_of_array.c -Wall && a.exe & echo    Return code:%ERRORLEVEL%
*/

//----------USER define------------
#define DEBUG       0    // print auxiliary text or not
#define TEXT_SIZE 128    // size of input text in bytes
#define SPILTOR   " "    // a character that spilts input array, for example "10 38 21 70 43"
#define REPT_TIMES  9    // how many times of execution for reading input, calculating and ouput.
//------END USER define------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x, y) (x<y?x:y)
#define SWAP(t, x, y) {t tmp = x; x = y; y = tmp;} //usage: SWAP(int, a, b);


int main(){
  
  unsigned int counts;  // item counts in the input array
  char* text;             // input text
  int* array;             // int array parsed from text
  long product;
  char* item;             // an item in the input array
  text=calloc(TEXT_SIZE, sizeof(char));
  //for(;;){
  for(int times=0; times<REPT_TIMES; times++){
    if(DEBUG)
      printf("Please enter an numerical array, spilted with space.\n:");
    //fgets(text, TEXT_SIZE-2, stdin);
    scanf(" %[^\n]", text);
    
    if(DEBUG){
      printf("The text you entered:%s\n", text);
      printf("strlen(text):%d\n", strlen(text));
    }
    if(strlen(text)==1)
      exit(0);
    // count for how many spaces
    counts=1;
    for(unsigned int i=0; i<TEXT_SIZE-1; i++){
      if     (text[i]==SPILTOR[0]) counts++;
      else if(text[i]=='\0')       break;
    }
    
    if(DEBUG)
      printf("Array counts:%d\n", counts);
    
    // assign size of rev_array={"10", "12", "83", "23"};
    item=strtok(text, (char*)SPILTOR);  //get the first item in text
    array=calloc(counts, sizeof(int));
    product=1;
    for(unsigned int i=0; i<counts; i++){
      array[i]=atoi(item);
      product*=array[i];
      item=strtok(NULL, (char*)SPILTOR);
    }
    
    printf("%ld\n", product);
    free(array);
  }

  free(text);
  if(DEBUG)
    printf("\n\n\n\nProgram ended. ");
}
