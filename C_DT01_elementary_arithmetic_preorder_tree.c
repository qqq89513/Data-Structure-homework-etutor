/* 
  問題描述 ：
    寫一個程式，用"樹"計算一個算式。考慮這個算式4 + x * 7。我們會用下面的遞迴定義來表示此算式樹。
    首先，一個正整數或是變數是一個算式樹。再來，如果運算子是'+', '-', '*', 或 '/'的其中之一，
    並且左樹和右樹都是算式樹，則(運算子 左樹 右樹 )也是一個算式樹。按照此定義，我們可以用( + 4 ( * x 7 ) )來表示先前的算式。
    現在給定一個算式樹，以及其中所含的變數的值，請計算整個算式的值。
    Pre order: (root, left-node, right-node), (運算子 左樹 右樹 )

  輸入說明 ：
    輸入的第一行是一個算式樹，不超過1000個字元。注意樹中相鄰的兩個元素會以空白隔開。變數的名稱會是合法的C變數名稱([_A-Za-z0-9]並且非數字開頭)，且不超過32字元。接下來的n行( n ≤ 50，代表樹中變數的數目)以此格式： 變數 = 值 表示各個變數的值，同樣以空白隔開。

  輸出說明 ：
    輸出為這個算式樹的值。
  
  輸出輸入範例:
    第一個範例，4+(x*7), x=5
      ( + 4 ( * x 7 ) )         |39
      x = 5                     |
    第二個範例，4+3+(7*6)
      ( + 4 ( + 3 ( * 7 6) ) )   |49

  cmd compile and execution: rm a.exe & gcc C_DT01_elementary_arithmetic_preorder_tree.c -Wall && a.exe & echo    Return code:%ERRORLEVEL%
*/

//----------USER define------------
#define DEBUG        0   // print auxiliary text or not
#define TEXT_SIZE 1024   // size of input text in bytes
#define SPILTOR   " "    // a character that spilts input array, for example "( + 4 ( * 7 3 ) )"
#define MAX_VARIABLES 50 // maximum variables counts
//------END USER define------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long recur_solve_arith(char** arith);
char** str_to_str_array(char* str, char* spiltor, unsigned int counts);

int main(){
  unsigned int counts=1;      // item counts in the input array
  unsigned int var_counts=0;  // how many variables there are in the text
  char* text;                 // input text
  int var_list[MAX_VARIABLES];
  char** arith_array;         // if text="( + 4 ( * 7 3 ) )", then arith_array[]={"(", "+", "4", "(", "*", "7", "3", ")", ")"};
  text=calloc(TEXT_SIZE, sizeof(char));
  
  if(DEBUG)
    printf("Please enter a mathmetic preorder tree, spilted with space:\n:");
  //fgets(text, TEXT_SIZE-2, stdin);
  scanf("%[^\n]", text);
  getchar();
  
  if(DEBUG){
    printf("The text you entered:%s\n", text);
    printf("strlen(text):%I64d\n", strlen(text));
  }
  
  // count for how many spiltor
  for(unsigned int i=0; i<TEXT_SIZE-1; i++){
    if     (text[i]==SPILTOR[0])  counts++;
    else if(text[i]=='\0')        break;
  }
  
  if(DEBUG)
    printf("Array counts:%d\n", counts);

  arith_array=str_to_str_array(text, SPILTOR, counts);


  // count for varialbes and record where they are
  for(unsigned int i=0; i<counts; i++){
    switch (arith_array[i][0]){
      case '(':;  case ')':;
      case '+':;  case '-':;  case '*':;  case '/':;
      case '0':;  case '1':;  case '2':;  case '3':;  case '4':;
      case '5':;  case '6':;  case '7':;  case '8':;  case '9':
        break;
      default:
        var_list[var_counts++]=i;
        break;
    }
  }

  // print the variables
  if(DEBUG){
    printf("Varible counts:%d\n",var_counts);
    printf("Variables:");
    for(unsigned int i=0; i<var_counts; i++)
      printf("%s ", arith_array[ var_list[i] ]);
    printf("\n");
  }

  // replace the varialbes with their values
  int var_counts_flag=var_counts;
  while(var_counts_flag){
    char** var_assign;
    char text[50];
    if(DEBUG)   printf("\nPlease enter the \"variable name = value\":");
    scanf("%[^\n]", text);
    getchar();   // to remove \n in the buffer
    var_assign=str_to_str_array(text, SPILTOR, 3); // ex:x = 4, 3 elements
    for(unsigned int j=0; j<var_counts; j++){
      unsigned int index=var_list[j];
      if(strcmp(var_assign[0], arith_array[index])==0){
        strcpy(arith_array[index], var_assign[2]);
        var_counts_flag--;
        // print the replacement of variables
        if(DEBUG){
          printf("Replace %s with %s.\n", var_assign[0], arith_array[index]);
        }
      }
    }
    free(var_assign[0]); free(var_assign[1]); free(var_assign[2]);
    free(var_assign);
  }

  // print the input captured
  if(DEBUG){
    printf("Input mathmetic problem in preorder tree:");
    for(unsigned int i=0; i<counts; i++)  printf("%s ", arith_array[i]);
    printf("\n");
  }

  if(DEBUG)
    printf("The result:");
  printf("%ld\n", recur_solve_arith(arith_array));

  for(unsigned int i=0; i<counts; i++)
    free(arith_array[i]);
  free(arith_array);
  free(text);
  if(DEBUG)
    printf("\n\n\n\nProgram ended. ");
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

// return: the result of arithmetic preorder binary tree
long recur_solve_arith(char** arith){
  if(arith[0][0]=='('){                 // the 0th element of arith is "("
    long a=atol(arith[2]);              // the 2nd element of arith is the left tree(or node)
    long b=recur_solve_arith(arith+3);  // the 3rd element of arith is the right tree(or node)
    switch (arith[1][0]){               // the 1tst element of arith is an operand, the root
      case '+':   return a+b;
      case '-':   return a-b;
      case '*':   return a*b;
      case '/':   return a/b;
      default:    printf("Unknow Operator:%s\n",arith[1]);
    }
  }
  else // no more brackets
    return atol(arith[0]);  // this is the most bottom-right node
  return -1;
}
