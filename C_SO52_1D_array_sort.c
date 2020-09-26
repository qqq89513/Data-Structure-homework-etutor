/* 
  問題描述 ：
    老師排序班上成績之高低係一經常性需處理之問題，請試著將一大筆成績資料，運用排序演算法，依高至低方式依序排列之。
  
  輸入說明 ：
    第一列會有一個數字 n 代表 成績之筆數， 接下來會有 n 筆介於 2~50 之不同成績測試資料，每筆一列， 2<n<26 。
  
  輸出說明 ：
    對於每筆輸入 成績 測試資料依序輸出編號及排序結果。

  輸入:
    5
    31
    90
    28
    35
    61
  輸出:
    1 90
    2 61
    3 35
    4 31
    5 28
  cmd compile and execution: rm a.exe & gcc C_SO52_1D_array_sort.c -Wall && a.exe & echo    Return code:%ERRORLEVEL%
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
  
  unsigned int counts;  // item counts in the input array
  int* array;           // int array from input

  if(DEBUG)
    printf("Please enter the array elements count:");
  scanf(" %d", &counts);
  array=calloc(counts, sizeof(int));
  if(DEBUG)
    printf("Please enter a numerical array, spilted with space.\n:");
  for(unsigned int i=0; i<counts; i++){
    scanf(" %d", array+i);
  }
  
  insertion_sort(array, counts);
  for(unsigned int i=0; i<counts; i++)
    printf("%d %d\n", i+1, array[i]);
  free(array);
  if(DEBUG)
    printf("\n\n\n\nProgram ended. ");
}

void insertion_sort(int *array, size_t len){
  for(size_t i=0; i<(len-1); i++)
  {  //insertion sorting
    int j=0;//j is potential to be negative
    int temp=array[i+1];//array[i+1] is the first one to be replaced when array[j]<array[temp]
    for(j=i; j>=0&&array[j]<temp; j--)//when i=0, and array[j]<temp, after the first loop, j becomes -1
      array[j+1]=array[j];  //moving the array forward
    array[j+1]=temp;
  }
}
