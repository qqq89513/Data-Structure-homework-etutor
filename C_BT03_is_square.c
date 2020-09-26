/* 
  問題描述 :
    輸入線段的個數，以及每個線段的長度，判斷這些線段是否能夠組成一個三角形。
  
  輸入說明 :
    輸入的第一個數為線段個數，接下來依序為每個線段的長度。火柴長度皆大於零。
  
  輸出說明 :
    要是可以組成三角形，則輸出 true ，否則輸出 false 。
  
  範例:
    input                  |output
    4 1 1 1 1              |yes
    5 10 20 30 40 50       |no
    8 9 6 10 23 7 8 4 1    |no
    8 1 7 2 6 4 4 3 5      |yes
    4 1 2 3 4              |no

  cmd compile and execution: rm a.exe & gcc C_BT03_is_square.c -Wall && a.exe & echo    Return code:%ERRORLEVEL%
*/

//----------USER define------------
#define DEBUG       0    // print auxiliary text or not
#define TEXT_SIZE 128    // size of input text in bytes
#define SPILTOR   " "    //a character that spilts input array, for example "10 38 21 70 43"
//------END USER define------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  
  unsigned int counts=1;  // item counts in the input array
  int sum=0;              // sum of elements of arr
  int* arr;
  char* text;             // input text
  char* item;             // an item(substring) in the input array
  text=calloc(TEXT_SIZE, sizeof(char));
  if(DEBUG)
    printf("Please enter an int array, spilted with space.\n:");
  //fgets(text, TEXT_SIZE-2, stdin);
  scanf("%[^\n]", text);
  
  if(DEBUG){
    printf("The text you entered:%s\n", text);
    printf("strlen(text):%d\n", strlen(text));
  }
  
  if(DEBUG)
    printf("Array counts:%d\n", counts);
  
  item=strtok(text, (char*)SPILTOR);  //get the first item in text
  counts=atoi(item);
  arr     =calloc(counts, sizeof(int));
  item=strtok(NULL, (char*)SPILTOR);
  for(unsigned int i=0; i<counts; i++){  //counts-1 due to the first execution is alread done before this loop
    arr[i]=atoi(item);
    sum+=arr[i];
    if(DEBUG) printf("arr[%d]=%d\n", i, arr[i]);
    item=strtok(NULL, (char*)SPILTOR);
  }

  int not_flag=0;
  for(unsigned int i=0; i<counts; i++){
    if(arr[i]>sum/4){
      not_flag++;
      break;
    }
  }
  
  if(not_flag)   printf("no\n");
  else           printf("yes\n");

  free(arr);
  free(text);
  if(DEBUG)
    printf("\n\n\n\nProgram ended. ");
}


