/* 
  問題描述 ：
    寫一個程式來找出輸入的十個數字的最大值和最小值，數值不限定為整數，且值可存放於 float 型態數值內。

  輸入說明 ：
    輸入十個數字，以空白間隔。

  輸出說明 ：
    輸出數列中的最大值與最小值，輸出時需附上小數點後兩位數字。

  cmd compile and execution: rm a.exe & gcc C_AR146_max_min.c -Wall && a.exe & echo    Return code:%ERRORLEVEL%
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
#define MAX(x, y) (x>y?x:y)
#define SWAP(t, x, y) {t tmp = x; x = y; y = tmp;} //usage: SWAP(int, a, b);




int main(){
  
  unsigned int counts=1;  // item counts in the input array
  char* text;             // input text
  float min, max, temp;
  char* item;             // an item(substring) in the input array
  text=calloc(TEXT_SIZE, sizeof(char));

  if(DEBUG)
    printf("Please enter an float array, spilted with space.\n:");
  //fgets(text, TEXT_SIZE-2, stdin);
  scanf("%[^\n]", text);
  
  if(DEBUG){
    printf("The text you entered:%s\n", text);
    printf("strlen(text):%d\n", strlen(text));
  }
  
  // count for how many spaces
  for(unsigned int i=0; i<TEXT_SIZE-1; i++){
    if     (text[i]==SPILTOR[0]) counts++;
    else if(text[i]=='\0')       break;
  }
  
  if(DEBUG)
    printf("Array counts:%d\n", counts);
  
  // assign size
  item=strtok(text, (char*)SPILTOR);  //get the first item in text
  temp=atof(item);
  max=temp;
  min=temp;
  for(unsigned int i=0; i<counts-1; i++){  //counts-1 due to the first execution is alread done before this loop
    item=strtok(NULL, (char*)SPILTOR);
    temp=atof(item);
    max=MAX(temp, max);
    min=MIN(temp, min);
  }
  
  printf("maximum:%.2f\n", max);
  printf("minimum:%.2f\n", min);

  free(text);
  if(DEBUG)
    printf("\n\n\n\nProgram ended. ");
}
