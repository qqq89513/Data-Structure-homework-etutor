/* 
  Given a numerical array input, verified if any items are repetitive.
  input 1: First line is a number between 1~128, representing the item counts of the second line
  input 2: Second line is a numerical array input, spilted with space. Values of items are between 1 to the number input in the first line.
  ouput:0 if any items are repetitive, 1 otherwise.
  
  cmd compile and execution: rm a.exe & gcc C_AR20_repetitive.c && a.exe & echo    Return code:%ERRORLEVEL%
*/

//----------USER define------------
#define DEBUG       0    // print auxiliary text or not
#define TEXT_SIZE 128    // size of input text in bytes
#define SPILTOR   " "    //a character that spilts input array, for example "10 38 21 70 43"
//------END USER define------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x, y) (x<y?x:y)
#define SWAP(t, x, y) {t tmp = x; x = y; y = tmp;} //usage: SWAP(int, a, b);


int main(){
  
  unsigned int counts;  // item counts in the input array
  char* text;             // input text
  int*  int_array;        // parsed from the input text
  char* rep_flag;         // check if any item is repetitive
  char* item;             // an item in the input array
  text=calloc(TEXT_SIZE, sizeof(char));
  
  if(DEBUG)
    printf("Please enter the array item counts:");
  scanf("%d", &counts);
  getchar();  // remove newline that scanf() leaves in the buffer

  if(DEBUG)
    printf("Please enter an numerical array, spilted with space:");
  //fgets(text, TEXT_SIZE-2, stdin);
  scanf(" %[^\n]", text);
  
  if(DEBUG){
    printf("The text you entered:%s\n", text);
    printf("strlen(text):%d\n", strlen(text));
  }
  
  if(DEBUG)
    printf("Array counts:%d\n", counts);
  
  // assign size
  int_array=calloc(counts, sizeof(int));
  rep_flag =calloc(counts, sizeof(char));

  item=strtok(text, (char*)SPILTOR);  //get the first item in text
  for(unsigned int i=0; i<counts; i++){
    int num=atoi(item)-1;  // convert string to int
    int_array[i]=num;
    rep_flag[num]++;
    if(int_array[i]<0 || int_array[i]>counts-1)
      exit(87);
    else if(rep_flag[num]>1){
      printf("0\n");
      goto EXIT;
    }
    if(DEBUG)printf("repflag[%d]:%d\n", num, rep_flag[num]);
    item=strtok(NULL, (char*)SPILTOR);
  }
  printf("1\n");


EXIT:
  free(int_array);
  free(rep_flag);
  free(text);
  if(DEBUG)
    printf("\n\n\n\nProgram ended. ");
  return 0;
}
