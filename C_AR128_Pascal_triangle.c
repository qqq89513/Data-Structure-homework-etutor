/* 
  問題描述  
    巴斯卡三角形（ Pascal's Triangle ）的頂端是 1 ，視為 row 0 。
    第 1 列 (row 1) 為兩個 1 ，這兩個 1 是由他們上頭左右兩數之和（不在三角形內的數視為 0 ）。
    依此類推產生第 2 列 (row 2): 0+1= 1 ; 1+1= 2 ; 1+0= 1 。第 3 列 (row 3): 0+1= 1 ; 1+2= 3 ; 2+1= 3 ; 1+0= 1 。
    循此法可以產生一巴斯卡三角形。
    每列由左而右各數，分別命名為第 0 元素，第 1 元素， … ，如此第 n 列第 r 元素是 (n!)/( r!*(n-r)! )。
    請寫一個程式將巴斯卡三角形中之指定列的指定元素印出來。每筆測試資料結果輸出於一行 ， 最後必須有換行字元 。
  輸入說明  
    輸入檔中第一行為一個正整 數 N ( 0 N N 組測試資料。
    之後接下來有 N 行，每行有兩個整數，第一個整數 n，代表巴斯卡三角形中之第 n 列 ( 0 ≤ n ≤ 65 ) 第二個整數 m 代表該列由左而右第 m 個元素 ( 從 0 起算 ) 。
  範例輸入  
    3
    0 0
    3 1
    10 4
  範例輸出  
    1
    3
    210
*/

//----------USER define------------
#define DEBUG       0    // print auxiliary text or not
#define TEXT_SIZE 128    // size of input text in bytes
#define SPILTOR   " "    // a character that spilts input array, for example "10 38 21 70 43"
//------END USER define------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x, y) (x<y?x:y)
#define SWAP(t, x, y) {t tmp = x; x = y; y = tmp;} //usage: SWAP(int, a, b);

void* CALLOC(size_t _NumOfElements, size_t _SizeOfElements){
  void* ptr=calloc(_NumOfElements, _SizeOfElements);
  if(ptr==NULL){
    printf("Insufficient memmory when requiring Num=%I64d, Size=%I64d. Program exits here.\n", _NumOfElements, _SizeOfElements);
    exit(EXIT_FAILURE);
  }
  else return ptr;
}

long fact(long N){
  if(N<=0)
    N=1;    // defination of factorail, 0!=1
  else
    for( long i=N-1; i>0; i--)
      N*=i; // compute factorail

  return N;
}

int main(){
  int counts;
  int row, item;
  char* text;                // text from input

  text=CALLOC(TEXT_SIZE, sizeof(char));
  counts=atoi(fgets(text, TEXT_SIZE-1, stdin));
  
  if(DEBUG)   printf("Please enter how many following test-case inputs are there:");

  for(unsigned int i=0; i<counts; i++){
    scanf(" %d %d", &row, &item);
    if(DEBUG)   printf("Pascal triangle, row:%d, item:%d, value:", row, item);
    printf("%ld\n", fact(row)/( fact(item)*fact(row-item) ));
  }


  free(text);
  if(DEBUG)   printf("\n\n\n\nProgram ended. ");
}
