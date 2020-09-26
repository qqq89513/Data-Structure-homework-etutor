/* 
  問題描述 ：
    一個二元圖形通常用一個二維陣列表示，其中的值為0或1，即為淺色（以1表）圖形在深色（以0表）的背景中。在分析圖形時往往需要找出其邊緣，稱之為邊緣偵測。所謂”邊緣”即為一個1的pixel其上下左右至少有一個為0。寫一個程式讀入二元圖形，輸出該圖之邊緣。
  
  輸入說明 ：
    第一行為一個正整數N，代表共有幾組測試資料。之後接下來有N組數據，每組第一行為兩個正整數n及m，表示二元圖形的大小，之後n行每行有m個數字（1 ≤ n,m ≤ 80 ，每個數字中間有一個空格），分別是0或1，即為該組測試資料之二元圖形。

  輸出說明 ：
    將不是邊緣的點以底線‘_’表示，邊緣的點則以0表示，每個測試資料結果之間空一行。
    
  Sample input:              ||Sample output:
    2                        ||_ _ _ _ _ _ _
    5 7                      ||_ _ 0 0 0 _ _
    0 0 0 0 0 0 0            ||_ 0 _ _ _ 0 _
    0 0 1 1 1 0 0            ||_ _ 0 0 0 _ _
    0 1 1 1 1 1 0            ||_ _ _ _ _ _ _
    0 0 1 1 1 0 0            ||
    0 0 0 0 0 0 0            ||_ _ _ _ _ _ _ _ _ _ _
    8 11                     ||_ _ 0 0 _ _ _ 0 0 _ _
    0 0 0 0 0 0 0 0 0 0 0    ||_ 0 _ _ 0 _ 0 _ _ 0 _
    0 0 1 1 0 0 0 1 1 0 0    ||_ _ 0 _ _ 0 _ _ 0 _ _
    0 1 1 1 1 0 1 1 1 1 0    ||_ _ _ 0 _ _ _ 0 _ _ _
    0 0 1 1 1 1 1 1 1 0 0    ||_ _ _ _ 0 _ 0 _ _ _ _
    0 0 0 1 1 1 1 1 0 0 0    ||_ _ _ _ _ 0 _ _ _ _ _
    0 0 0 0 1 1 1 0 0 0 0    ||_ _ _ _ _ _ _ _ _ _ _
    0 0 0 0 0 1 0 0 0 0 0    ||
    0 0 0 0 0 0 0 0 0 0 0    ||

  cmd compile and execution: rm a.exe & gcc C_AR04_2D_edge_detection.c && a.exe & echo    Return code:%ERRORLEVEL%
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
  
  unsigned int counts;  // array counts
  char* text;           // input text
  int   x_size, y_size; // size of 
  char** array_in;      // parsed from the input text
  char** array_out;     // result array to output
  text=calloc(TEXT_SIZE, sizeof(char));
  
  if(DEBUG)
    printf("Please enter how many 2D array:");
  scanf("%d", &counts);
  getchar();  // remove newline that scanf() leaves in the buffer

  for(unsigned int times=0; times<counts; times++){
    if(DEBUG)
      printf("Please enter the size of first dimension \"x y\":");
    scanf("%d %d", &x_size, &y_size);
    getchar();  // remove newline that scanf() leaves in the buffer
    if(DEBUG){
      printf("x_size:%d, y_size:%d\n", x_size, y_size);
      printf("Please enter an binaray 2D array, spilted with space:\n");
    }
    
    array_in  = calloc(x_size, sizeof(char*));    // assign how many 1D char array
    array_out = calloc(x_size, sizeof(char*));
    
    // read the input text and parse it into 2D array
    for(unsigned int x=0; x<x_size; x++){
      //fgets(text, TEXT_SIZE-2, stdin);
      scanf(" %[^\n]", text);
      array_in[x] =calloc(y_size, sizeof(char));
      array_out[x]=calloc(y_size, sizeof(char));
      unsigned int text_len=strlen(text);
      unsigned int y=0;
      for(unsigned int i=0; i<text_len; i++){
        switch (text[i]){
          case '0':
          case '1':
            array_in[x][y++]=text[i];
            break;
          case ' ':
            continue;
          case '\0':
            break;
          default:
            // printf("Wrong input array element:%c, %d\n", text[i], text[i]);
            break;
        }
      }
    }
    
    if(DEBUG){
      printf("The 2D array you entered:\n");
      for(unsigned int x=0; x<x_size; x++){
        for(unsigned int y=0; y<y_size; y++)
          printf("%c ", array_in[x][y]);
        printf("\n");
      }
    }

    for(unsigned int x=0; x<x_size; x++){
      for(unsigned int y=0; y<y_size; y++){
        if(array_in[x][y]=='0')
          array_out[x][y]='_';
        else if(array_in[x+1<x_size?x+1:x][y]=='1' && array_in[x-1>=0?x-1:x][y]=='1' && 
                array_in[x][y+1<y_size?y+1:y]=='1' && array_in[x][y-1>=0?y-1:y]=='1')
          array_out[x][y]='_';
        else
          array_out[x][y]='0';
      }
    }

    if(DEBUG) printf("The 2D array with edge detection:\n");
    for(unsigned int x=0; x<x_size; x++){
      for(unsigned int y=0; y<y_size; y++){
        printf("%c", array_out[x][y]);
        if(y<y_size-1)  printf(" ");
      }
      free(array_in[x]);
      free(array_out[x]);
      printf("\n");
    }

    free(array_in);
    free(array_out);
    if(times!=counts-1)
      printf("\n");
  }
  free(text);
  if(DEBUG)
    printf("\n\n\n\nProgram ended. ");
  return 0;
}


