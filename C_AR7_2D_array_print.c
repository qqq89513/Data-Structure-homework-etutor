/* 
  問題描述：
    二維陣列反轉，陣列內容如下：
  提示：
    1. 請先輸入陣列大小
    2. 第一個輸入的數為列，第二個輸入的數為行
    3. 如 3X3 得陣列，反轉後如下 :
        1 2 3          9 8 7
        4 5 6  反轉後  6 5 4
        7 8 9          3 2 1
  
  輸入：
    3
    3
  輸出說明：
    9 8 7
    6 5 4
    3 2 1
  
  cmd compile and execution: rm a.exe & gcc C_AR7_2D_array_print.c && a.exe & echo    Return code:%ERRORLEVEL%
*/

//----------USER define------------
#define DEBUG       0    // print auxiliary text or not
#define TEXT_SIZE 128    // size of input text in bytes
#define SPILTOR   " "    // a character that spilts input array, for example "10 38 21 70 43"
//------END USER define------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int col, row;

  if(DEBUG)
    printf("Enter column counts:");
  scanf(" %d", &col);
  if(DEBUG)
    printf("Enter column counts:");
  scanf(" %d", &row);
  if(DEBUG)
    printf("col:%d, row:%d\n", col, row);

  for(int i=col*row; i>0; i--){
    printf("%d", i);
    if((i-1)%row!=0)  printf(" ");
    else              printf("\n");
  }

  if(DEBUG)
    printf("\n\n\n\nProgram ended. ");
}