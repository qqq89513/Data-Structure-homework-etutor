/* 
  問題描述：
    在電腦科學上 ，計算一串文字上各個字母出現的頻率是常被用到的技術，這對壓縮來講是很重要的資訊，而計算字數也可以幫助人們作校正的工具。一行文字被空白、逗點或是句點所分隔而形成很多字，例如 ”I have a pencil.” 這行字就有 I ， have ， a ， pencil 這四個字，即此行字數為 4 。所以現在要請你幫忙設計一個程式來計算一行文字的字 數及各個字母出現的次數。

  輸入說明：
    輸入一行正常的英文文字，也就是不要有開頭是空白或是有連續兩個 空白的情形發生，並且內容只能包含英文字母、空白、逗點、句點。 注意 : 輸入的字串長度最多是 100 。

  輸出說明：
    第一行輸出一個正整數 n ，表示此行文字的字數。 第二行開始依序輸出在此行文字中有出現的字母及出現的次數。 注意 : 大小寫要分開計算。
    格式：出現的字母(空格)：(空格)出現的次數
  
  cmd compile and execution: rm a.exe & gcc C_ST21_word_letter_count.c -Wall && a.exe & echo    Return code:%ERRORLEVEL%
*/

//----------USER define------------
#define DEBUG       0    // print auxiliary text or not
#define TEXT_SIZE 128    // size of input text in bytes
#define SPILTOR   " "    // a character that spilts input array, for example "10 38 21 70 43"
//------END USER define------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARACTER_COUNT 128
#define MIN(x, y) (x<y?x:y)
#define SWAP(t, x, y) {t tmp = x; x = y; y = tmp;} //usage: SWAP(int, a, b);


int main(){
  
  unsigned int counts=1;  // item(word) counts in the input array
  unsigned int len=0;     // strlen(text)
  char* text;             // input text
  char* repet;            // repetitive counts
  repet=calloc(CHARACTER_COUNT, sizeof(char));
  text =calloc(TEXT_SIZE, sizeof(char));
  
  if(DEBUG)
    printf("Please enter a sentence(spilted word with space).\n:");
  
  //fgets(text, TEXT_SIZE-2, stdin);
  scanf("%[^\n]", text);
  
  if(DEBUG){
    printf("The text you entered:%s\n", text);
    printf("strlen(text):%d\n", strlen(text));
  }
  
  // count for how many words
  for(unsigned int i=0; i<TEXT_SIZE-1; i++){
    if     (text[i]==SPILTOR[0]) counts++;
    else if(text[i]=='\0')       break;
  }
  
  if(DEBUG)
    printf("Word counts:");
  printf("%d\n",counts);

  len=strlen(text);
  for(unsigned int i=0; i<len; i++)
    repet[text[i]]++;   // different letter count
  
  for(char i='A'; i<='Z'; i++){
    if(repet[i]>0)
      printf("%c : %d\n", i, repet[i]);
    else if(repet[i-'A'+'a']>0)
      printf("%c : %d\n", i-'A'+'a', repet[i-'A'+'a']);
  }

  free(repet);
  free(text);
  if(DEBUG)
    printf("\n\n\n\nProgram ended. ");
}