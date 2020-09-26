/* 
  問題描述：
    試寫一個程式，可以繪製出如下的圖形：（若輸入偶數，將自動少一行 ) 。
    PS:若輸入偶數，將自動少一行 ,是因為星號數是1,3,5,7,...,5,3,1的規律,是以奇數行為成長,所以輸入8的話,輸出會和7一樣(沒有8行的菱形)

  輸入說明：
    輸入一個正整數。
  
    Sample input: ||Sample output:
      7           ||   *
                  ||
                  ||  ***
                  ||
                  || *****
                  ||
                  ||*******
                  ||
                  || *****
                  ||
                  ||  ***
                  ||
                  ||   *

  cmd compile and execution: rm a.exe & gcc C_ST11_stars.c && a.exe & echo    Return code:%ERRORLEVEL%
*/

//----------USER define------------
#define DEBUG       1    // print auxiliary text or not
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
  unsigned int i;       // row of for-loop iterative indsx
  if(DEBUG)
    printf("Please enter how many row of stars:");
  scanf("%d", &counts);
  getchar();  // remove newline that scanf() leaves in the buffer

  if(counts%2==0)
    counts--;
  for(i=0; i<=counts/2; i++){
    for(unsigned int space=0; space<counts/2-i; space++)
      printf(" ");
    for(unsigned int star=0;  star<i*2+1;       star++)
      printf("*");
    printf("\n");
  }
  for(i=i; i<counts; i++){
    for(unsigned int space=0; space<i-counts/2; space++)
      printf(" ");
    for(unsigned int star=0;  star<counts-(i-counts/2)*2; star++)
      printf("*");
    printf("\n");
  }

  if(DEBUG)
    printf("\n\n\n\nProgram ended. ");
  return 0;
}
