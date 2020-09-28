/*
問題描述  
  河內塔遊戲中有三根支架 A 、 B 、 C ，每根支架最多可放 n 個大小不同、中心挖孔的圓盤，大圓盤不得放在小圓盤上面。
  起先 n 個圓盤均置於支架 A 上(如圖一所示，以 n=3 為例)。
  今欲將這 n 個圓盤從支架 A 搬到支架 C ，每次只能搬一個盤子，支架 B 當作暫存處，請問共須搬動多少次的盤子才能完成？
  請寫一個非遞迴( non-recursive )程式來處理這個問題。為簡單起見，這 n 個圓盤以數字 1 到 n 來表示，大數字代表大盤子，圓盤置於支架之情形用橫式表示，請參考 Sample Output 。
輸入說明  
  輸入圓盤之個數 n ( 3 ≦ n ≦ 8 )
輸出說明  
  程式開始時顯示圓盤之個數n及支架A、B、C上圓盤放置情形(參考 Sample Output ，以 n=3 為例)，當搬動之次數為 5 之倍數( 5, 10, 15, … )時，需顯示 A 、 B 、 C 支架上圓盤放置之情形，並印出已經搬動盤子的次數。螢幕印滿後暫停，按任何鍵再繼續執行，直到完成後，顯示此 n 個盤子已搬至支架 C 上，並印出搬動之總次數。

範例  
  輸入:
    3
  輸出:
    Number of Discs: 3
    ***********************************
    Initial State:
    A: 3 2 1
    B:
    C:
    ***********************************
    After Moved 5 Times:
    A: 1
    B: 2
    C: 3
    ***********************************
    :
    :
    :
    ***********************************
    Total Moved 7 Times:
    A:
    B:
    C: 3 2 1
*/

//----------USER define------------
#define DEBUG       0    // print auxiliary text or not
//------END USER define------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x, y) (x<y?x:y)
#define SWAP(t, x, y) {t tmp = x; x = y; y = tmp;} //usage: SWAP(int, a, b);

int steps=0;
int* tower_A;   int idx_A;    // idx_A=height-1;
int* tower_B;   int idx_B=0;
int* tower_C;   int idx_C=0;       // tower A,B,C, treated as stack
int height;     // initial height of tower A

void disp(int final){
  if(DEBUG || steps==0 || steps%5==0 || final){
    printf("***********************************\n");
    if(steps==0)                    printf("Initial State:\n");
    else if(steps%5==0 && final==0) printf("After Moved %d Times:\n", steps);
    else if(final)                  printf("Total Moved %d Times:\n", steps);

    printf("A: ");
    for(unsigned int i=0; i<height; i++){
      if(tower_A[i]!=0){
        printf("%d", tower_A[i]);
        if(i==height-1)          printf("\n");
        else if(tower_A[i+1]==0) continue;
        else                     printf(" ");
      }
      else{
        printf("\n");
        break;
      }
    }
    printf("B: ");
    for(unsigned int i=0; i<height; i++){
      if(tower_B[i]!=0){
        printf("%d", tower_B[i]);
        if(i==height-1)          printf("\n");
        else if(tower_B[i+1]==0) continue;
        else                     printf(" ");
      }
      else{
        printf("\n");
        break;
      }
    }
    printf("C: ");
    for(unsigned int i=0; i<height; i++){
      if(tower_C[i]!=0){
        printf("%d", tower_C[i]);
        if(i==height-1)          printf("\n");
        else if(tower_C[i+1]==0) continue;
        else                     printf(" ");
      }
      else{
        printf("\n");
        break;
      }
    }
  }
}

void tower(int n, char from, char buffer, char to){
  if(n==1){
    if(DEBUG)  printf("%c -> %c\n", from, to);
    // to.push( from.pop() );
    int* ptr;
    if     (from=='A') ptr=(tower_A+(--idx_A));
    else if(from=='B') ptr=(tower_B+(--idx_B));
    else if(from=='C') ptr=(tower_C+(--idx_C));
    else  printf("Error: unknow \"from\" address of tower.\n");

    if     (to=='A') tower_A[idx_A++]=*(ptr);
    else if(to=='B') tower_B[idx_B++]=*(ptr);
    else if(to=='C') tower_C[idx_C++]=*(ptr);
    else  printf("Error: unknow \"to\" address of tower.\n");
    *(ptr)=0;

    steps++;
    disp(0);
  }
  else{
    tower(n-1, from, to, buffer);
    tower(1  , from, buffer, to);
    tower(n-1, buffer, from, to);
  }
}

int main(){

  if(DEBUG)   printf("Please enter the height of Tower of Hanoi:");
  scanf(" %d", &height);
  printf("Number of Discs: %d\n", height);
  idx_A=height;
  tower_A=calloc(height, sizeof(int));
  tower_B=calloc(height, sizeof(int));
  tower_C=calloc(height, sizeof(int));
  for(unsigned int i=0; i<height; i++)  tower_A[i]=height-i;
  disp(0);
  tower(height, 'A', 'B', 'C');
  disp(1);

  free(tower_A);
  free(tower_B);
  free(tower_C);
  if(DEBUG)   printf("\n\n\n\nProgram ended. ");
}

