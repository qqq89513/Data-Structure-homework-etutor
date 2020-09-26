/* 
問題描述 ：
  最大遞增子數列為一個數列中所有遞增子數列的集合中元素最多的遞增子數列，例如:
      數列A： 1,2,2,3,1,8,7,5,4
      數列A之最大遞增子數列：1,2,3,8
  請寫出一個程式輸入一個以空白分隔的數列，輸出最大的遞增子數列。

輸入說明 ：
  請任意輸入一串整數數列，可以有正、負號，任兩組數字之間要逗點。
  例如: -1,-9,2,7,0,11,-98

輸出說明 ：
  輸出最大遞增子數列，任兩組數字之間要空格。例如:
  -1,2,7,11
  cmd compile and execution: rm a.exe & gcc C_DT05_longest_increasing_sub_array.c -Wall && a.exe & echo    Return code:%ERRORLEVEL%
*/

//----------USER define------------
#define DEBUG       0    // print auxiliary text or not
#define TEXT_SIZE 128    // size of input text in bytes
#define SPILTOR   ","    // a character that spilts input array, for example "10 38 21 70 43"
//------END USER define------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x, y) (x<y?x:y)
#define SWAP(t, x, y) {t tmp = x; x = y; y = tmp;} //usage: SWAP(int, a, b);


int main(){
  
  unsigned int counts=1;  // item counts in the input array
  int* arr;
  int* arr_max;  int count_max=0;
  int* arr_temp; int index_temp=0;
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
  
  // count for how many spaces
  for(unsigned int i=0; i<TEXT_SIZE-1; i++){
    if     (text[i]==SPILTOR[0]) counts++;
    else if(text[i]=='\0')       break;
  }
  
  if(DEBUG)
    printf("Array counts:%d\n", counts);
  
  arr     =calloc(counts, sizeof(int));
  arr_max =calloc(counts, sizeof(int));
  arr_temp=calloc(counts, sizeof(int));
  item=strtok(text, (char*)SPILTOR);  //get the first item in text
  for(unsigned int i=0; i<counts; i++){  //counts-1 due to the first execution is alread done before this loop
    arr[i]=atoi(item);
    item=strtok(NULL, (char*)SPILTOR);
  }
  
  // find the longest increasing sub array
  for(unsigned int i=0; i<counts; i++){
    index_temp=0;
    arr_temp[0]=arr[i];
    for(unsigned int j=i+1; j<counts; j++)
      if(arr_temp[index_temp]<arr[j]) arr_temp[++index_temp]=arr[j];
    
    index_temp++;
    if(index_temp>1 && index_temp>count_max){
      count_max=index_temp;
      memcpy_DIY(arr_max, arr_temp, count_max); // memcpy(dest_ptr, src_ptr, size)
      if(DEBUG){
        printf("\ncount_max:%d, ", count_max);
        for(unsigned int index=0; index<count_max; index++)
          printf(" %d", arr_max[index]);
      }
    }
  }

  if(DEBUG)
    printf("\nThe longest increasing sub array:");
  for(unsigned int i=0; i<count_max; i++)
    printf(i!=count_max-1? "%d," : "%d\n", arr_max[i]);


  free(arr);
  free(arr_max);
  free(arr_temp);
  free(text);
  if(DEBUG)
    printf("\n\n\n\nProgram ended. ");
}

int memcpy_DIY(void* dest, const void* src, size_t n){
  for(size_t i=0; i<n; i++)
    // cast the void pointer to int pointer
    ((int*)dest)[i]=((int*)src)[i];
  return 0;
}
