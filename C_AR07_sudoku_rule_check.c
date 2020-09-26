/*
  問題描述：
    輸入一個9*9的數字矩陣，其中每個元素均為0～9，其中0代表該格尚未填入數字。請撰寫一支程式判斷該矩陣是否符合數獨之規則。數獨的規則如下：
    (1)矩陣中的每一列（9個元素）只能出現1~9至多各一次。
    (2)矩陣中的每一行（9個元素）只能出現1~9至多各一次。
    (3)9個3*3的小矩陣（9個元素），亦分別只能出現1~9至多各一次。
  
  輸入：
    9*9的數字矩陣，其中每個元素均為0～9, 0代表該格尚未填入數字.

  輸出說明：
    若該輸入符合數獨規則，則輸出 true
    否則需輸出違反規則的列或行或區塊之編號，分別有三種：
    1.若為列違反規則，則輸出該列中違反規則之最小數字，格式為： row[?], #?，其中第1個’?’代表列編號；第2個’?’代表第一個違反的數字
    2.若為行違反規則，則輸出該行中違反規則之最小數字，格式為： column[?], #?，其中第1個’?’代表行編號；第2個’?’代表第一個違反的數字
    2.若為區塊違反規則，則輸出該區塊中違反規則之最小數字，格式為： block[?], #?，其中第1個’?’代表區塊編號；第2個’?’代表第一個違反的數字
    注意，所有的行、列、區塊編號均為1～9；區塊的編號採row-major。以下是blcok的編號:
      1 2 3
      4 5 6
      7 8 9
    PS:因為原本題目有些地方會有爭議,所以在這裡補充傷心原本的題目在"中文題庫")
    若輸出不是true時, 則依序輸出各個row, column, block有錯誤的數字(即是在範圍內有重複)
    即使此數字在row和column都會重複出現, 也要分別印出來(例如下面範例2的row2 #9, column1 #9)

    輸出輸入範例:
      input       |output
      023456789   |true
      456789123   |
      789123456   |
      231564897   |
      564897231   |
      897231564   |
      312605978   |
      645978312   |
      908312645   |

      023450789   |row2 #5
      956789523   |row2 #9
      659723456   |row3 #5
      231564807   |row3 #6
      504897231   |column1 #6
      897231564   |column1 #9
      302605978   |column2 #5
      605978412   |column4 #7
      908312605   |column7 #4
                  |column7 #5
                  |block1 #5
                  |block1 #6
                  |block1 #9
                  |block2 #7
                  |block3 #5

      020456789   |row2 #9
      496789123   |block1 #9
      789123456   |
      231564897   |
      564897231   |
      807231564   |
      312605978   |
      645978312   |
      908312645   |

      023452789   |row1 #2
      156789123   |row2 #1
      119123456   |row3 #1
      231564827   |row4 #2
      534897231   |row5 #3
      897231564   |row8 #4
      302605978   |colume1 #1
      645978412   |colume2 #3
      908312645   |colume6 #2
                  |colume7 #4
                  |colume8 #2
                  |block1 #1
                  |block2 #2
                  |block4 #3
                  |block6 #2
                  |block9 #4





  cmd compile and execution: rm a.exe & gcc C_AR07_sudoku_rule_check.c && a.exe & echo    Return code:%ERRORLEVEL%
*/

//----------USER define------------
#define DEBUG        1    // print auxiliary text or not
#define TEXT_SIZE   32    // size of input text in bytes
#define ROW_COL 9
//------END USER define------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  unsigned int counts;  // array counts
  int rep_flag=0;       // repetitive flag
  char* text;           // input text
  char* rep_cnt;        // repetitive count
  int** array_in;       // parsed from the input text
  text=calloc(TEXT_SIZE, sizeof(char));
  rep_cnt=calloc(ROW_COL+1, sizeof(char));

  if(DEBUG)   printf("Please enter an %d*%d sudoku array:\n", ROW_COL, ROW_COL);

  array_in  = calloc(ROW_COL, sizeof(int*));    // assign how many 1D char array
  // read the input text and parse it into 2D array
  for(unsigned int y=0; y<ROW_COL; y++){
    //fgets(text, TEXT_SIZE-2, stdin);
    scanf(" %[^\n]", text);
    array_in[y] =calloc(ROW_COL, sizeof(int));
    unsigned int text_len=strlen(text);
    for(unsigned int x=0; x<text_len; x++)
      array_in[y][x]=text[x]-'0';
  }
  
  // print the input array
  if(DEBUG){
    printf("Input array:\n");
    for(unsigned int y=0; y<ROW_COL; y++){
      for(unsigned int x=0; x<ROW_COL; x++)
        printf("%d", array_in[y][x]);
      printf("\n");
    }
      
    printf("\n");
  }

  // check for row repetitive
  for(unsigned int y=0; y<ROW_COL; y++){
    memset(rep_cnt, 0, ROW_COL+1);
    for(unsigned int x=0; x<ROW_COL; x++)   rep_cnt[ array_in[y][x] ]++;
    for(unsigned int i=1; i<=ROW_COL; i++){
      if(rep_cnt[i]>1){
        printf("row%d #%d\n", y+1, i);
        rep_flag++;
      }
    }
  }

  // check for column repetitve
  for(unsigned int x=0; x<ROW_COL; x++){
    memset(rep_cnt, 0, ROW_COL+1);
    for(unsigned int y=0; y<ROW_COL; y++)   rep_cnt[ array_in[y][x] ]++;
    for(unsigned int i=1; i<=ROW_COL; i++){
      if(rep_cnt[i]>1){
        printf("column%d #%d\n", x+1, i);
        rep_flag++;
      }
    }
  }

  // check for block repetitve
  for(unsigned int block=0; block<ROW_COL; block++){
    memset(rep_cnt, 0, ROW_COL+1);
    for(unsigned int y=(block/3)*3; y<(block/3)*3+3; y++){
      for(unsigned int x=(block%3)*3; x<(block%3)*3+3; x++)  rep_cnt[ array_in[y][x] ]++;
    }
    for(unsigned int i=1; i<=ROW_COL; i++){
      if(rep_cnt[i]>1){
        printf("block%d #%d\n", block+1, i);
        rep_flag++;
      }
    }
  }

  if(rep_flag==0)  printf("true\n");

  for(unsigned int y=0; y<ROW_COL; y++)
    free(array_in[y]);
  free(array_in);
  free(text);
  free(rep_cnt);
  if(DEBUG)
    printf("\n\n\n\nProgram ended. ");
  return 0;
}
