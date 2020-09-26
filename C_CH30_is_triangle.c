/* 
  問題描述 :
    輸入線段的個數，以及每個線段的長度，判斷這些線段是否能夠組成一個三角形。
  
  輸入說明 :
    輸入的第一個數為線段個數，接下來依序為每個線段的長度。火柴長度皆大於零。
  
  輸出說明 :
    要是可以組成三角形，則輸出 true ，否則輸出 false 。
  
  輸出入範例:
    輸入:6 5 3 6 2 7 9          |輸出:true
    輸入:8 5 3 6 2 7 9 10 18    |輸出:true
    輸入:6 18 1 2 100 5 9       |輸出:false
    輸入:4 2 31 5 9             |輸出:false
    輸入:2 10 5                 |輸出:false



  cmd compile and execution: rm a.exe & gcc C_CH30_is_triangle.c -Wall && a.exe & echo    Return code:%ERRORLEVEL%
*/

//----------USER define------------
#define DEBUG       0    // print auxiliary text or not
#define TEXT_SIZE 128    // size of input text in bytes
#define SPILTOR   " "    //a character that spilts input array, for example "10 38 21 70 43"
//------END USER define------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define IS_TRIANGLE(a, b, c) (a+b>c)&&(b+c>a)&&(a+c>b)


int main(){
  
  unsigned int counts=1;  // item counts in the input array
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
  
  arr     =calloc(counts, sizeof(int));
  item=strtok(text, (char*)SPILTOR);  //get the first item in text
  counts=atoi(item);
  item=strtok(NULL, (char*)SPILTOR);
  for(unsigned int i=0; i<counts; i++){  //counts-1 due to the first execution is alread done before this loop
    arr[i]=atoi(item);
    item=strtok(NULL, (char*)SPILTOR);
  }

  int tri_flag=0;
  for(unsigned int i=0; i<counts; i++){
    for(unsigned int j=i+2; j<counts; j++){
      if(IS_TRIANGLE(arr[i],arr[i+1],arr[j])){
        tri_flag++;
        break;
      }
    }
  }
  if(tri_flag)  printf("true\n");
  else          printf("false\n");
  

  free(arr);
  free(text);
  if(DEBUG)
    printf("\n\n\n\nProgram ended. ");
}


