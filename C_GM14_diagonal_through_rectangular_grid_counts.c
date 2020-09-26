/* 
  問題描述：
    給定兩個正整數 a 及 b ， a 、 b 形成一個矩形，其中 a 為矩形的長而 b 為矩形的寬。令此矩形由單位為 1 的正方形所組成，
    所以這個矩形中包含了 a × b 個正方形。
    請寫一個程式，計算這個矩形的對角線所穿過的小正方形數。
    舉例而言，6*8的矩形的對角線穿過了 12 個小正方形。在這個例子中，你要輸出 12。

  輸入說明：
    我們的輸入只有一行。一行中包含兩個數字，這兩個數字用逗號隔開。第一個數字是 a ，第二個數字則是 b
  
  輸出說明：
    將矩形對角線所穿過的小正方形數給輸出。

  範例輸入:
    6,8
  範例輸出:
    12
  
  cmd compile and execution: rm a.exe & gcc C_GM14_diagonal_through_rectangular_grid_counts.c && a.exe & echo    Return code:%ERRORLEVEL%
*/

//----------USER define------------
#define DEBUG       1    // print auxiliary text or not
#define TEXT_SIZE 128    // size of input text in bytes
#define SPILTOR   ","    // a character that spilts input array, for example "10 38 21 70 43"
//------END USER define------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Use Euclidean algorithm(輾轉消去法) to find the highest common factor
int hfc(int a, int b) {
  if( a == 0 || b == 0)
    return -1;
  while(a>0 && b>0){
    if(a>b)  a = a % b;
    else     b = b % a;
  }
  if( a == 0 )   return b;
  else           return a;
}

/* return an string(char*) array, whoes elements are parsed from str
  @str: a string containing elements spilted with the @spiltor
  @spiltor: a string which seperates the elements in @str
  @counts: how many elements are there in @str

  example:
    arr=str_to_str_array("hello 1 2 3 world", " ", 5);
    arr: {"hello", "1", "2", "3", "world"};

  note: remember to free each elements and arr itself
*/
char** str_to_str_array(char* str, char* spiltor, unsigned int counts){
  char** str_arr;
  char* item;     // an item in the input array
  str_arr=calloc(counts, sizeof(char*));
  item=strtok(str, (char*)spiltor);  //get the first item in text
  for(unsigned int i=0; i<counts; i++){
    // strlen(item)+1, +1 is due to '\0'
    str_arr[i]=calloc(strlen(item)+1, sizeof(char));
    strcpy(str_arr[i], item);
    item=strtok(NULL, (char*)spiltor);
  }
  return str_arr;
}


int main(){
  char text[TEXT_SIZE];
  char** arr_str;
  int col, row;
  arr_str=calloc(2, sizeof(char*));

  if(DEBUG)
    printf("Enter 2 numbers, spilted with comma(num1,num2):");
  fgets(text, TEXT_SIZE-1, stdin);
  arr_str=str_to_str_array(text, SPILTOR, 2);
  col=atoi(arr_str[0]);
  row=atoi(arr_str[1]);


  if(DEBUG)
    printf("The square grid counts that diagonal of the %d*%d rectangle passes through:", col, row);

  printf("%d\n", col+row-hfc(col, row));

  free(arr_str[0]);
  free(arr_str[1]);
  free(arr_str);
  if(DEBUG)
    printf("\n\n\n\nProgram ended. ");
  return 0;
}