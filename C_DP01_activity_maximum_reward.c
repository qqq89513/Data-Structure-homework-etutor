/* 
  問題描述：
    某甲預定於星期日 7:00~17:00 參加一些活動。為了不浪費時間，某甲希望當天參加的活動總收穫最多。
    假設每一活動有起迄時間及一正整數表示預期收穫量，每項活動全程參加之後，可得該項活動之預期收穫量。
    請寫一程式幫某甲選擇當天應參加的活動，以達成最高收穫量。
    請注意某甲在任何時間只能參加一活動，且一活動全程參加完畢後，才能再參加下一個活動。

  輸入說明：
    第一列有一個正整數，代表活動之個數 n ，請注意 n ≤ 10 。
    其後有 n 列，每一列代表一項活動，每一列之資料依序為活動名稱、活動起始參加時間、結束時間、及預期收穫量。各項資料之間，以一個空白分隔。
    活動名稱為英文字母(不超過 10 個字母)；時間為 24 小時制，以 4 個阿拉伯數字表示，且各時間均為整點時間(只有七時、八時、九時、十時 … )，
    例如 0800 表示上午八時， 1400 表示下午二時；預期收穫量為一個正整數。

  輸出說明：
    印出一列，依序列出可參加活動的活動名稱及其總收穫量。各項資料之間以一個空白分隔。

  輸出輸入範例:
    6
    A1 0700 0800 1
    A2 0800 1000 6
    A3 0800 0900 5
    A4 0900 1200 6
    A5 1000 1600 12
    A6 1300 1700 8
  輸出:
    A1 A3 A4 A6 20
  cmd compile and execution: rm a.exe & gcc C_DP01_activity_maximum_reward.c -Wall && a.exe & echo    Return code:%ERRORLEVEL%
*/

//----------USER define------------
#define DEBUG       1    // print auxiliary text or not
#define TEXT_SIZE 128    // size of input text in bytes
#define SPILTOR   " "    // a character that spilts input array, for example "10 38 21 70 43"
#define BEGIN_OF_DAY 700 // stands for 07:00 of a day
#define END_OF_DAY  1700 // stands for 17:00 of a day
#define SCH_SIZE (END_OF_DAY-BEGIN_OF_DAY)/100  // how many hours are there in a day for activities
//------END USER define------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x, y) (x>y?x:y)

struct activity {
  char* name;
  int strat;
  int end;
  int reward;
  int picked;
};


void* CALLOC(size_t _NumOfElements, size_t _SizeOfElements){
  void* ptr=calloc(_NumOfElements, _SizeOfElements);
  if(ptr==NULL){
    printf("Insufficient memmory when requiring Num=%I64d, Size=%I64d. Program exits here.\n", _NumOfElements, _SizeOfElements);
    exit(EXIT_FAILURE);
  }
  else return ptr;
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
  str_arr=CALLOC(counts, sizeof(char*));
  item=strtok(str, (char*)spiltor);  //get the first item in text
  for(unsigned int i=0; i<counts; i++){
    // strlen(item)+1, +1 is due to '\0'
    str_arr[i]=CALLOC(strlen(item)+1, sizeof(char));
    strcpy(str_arr[i], item);
    item=strtok(NULL, (char*)spiltor);
  }
  return str_arr;
}

/* return 1 if the schedule has free time(slots) for the activity
*/
int free_to_join(struct activity act, int* schedule, int sch_size){
  for(unsigned int t=act.strat; t<act.end; t++)
    if(schedule[t]!=-1) return 0; // no free time for the activity

  return 1;   // there is free time for the activity
}

int main(){
  unsigned int act_cnt;      // activity count from input
  char* text;                // text from input
  char** str_arr;            // string array parsed from text
  int* schedule;             // an array of size SCH_SIZE, stores the activities participate for all the day. -1 means for free time
  int* result_sch;           // the result schedule, stores the activities combination that earns max reward
  int max_reward=0;          // maximum reward among all the available combination of activities
  struct activity* act_all;  // stores all the activities parsed from input
  text=CALLOC(TEXT_SIZE, sizeof(char));
  schedule=CALLOC(SCH_SIZE, sizeof(int));
  result_sch=CALLOC(SCH_SIZE, sizeof(int));

  if(DEBUG)   printf("Please enter the how many activities are there:");
  act_cnt=atoi(fgets(text, TEXT_SIZE-1, stdin));
  act_all=CALLOC(act_cnt, sizeof(struct activity));

  // read activities from input and parse them into act_all
  if(DEBUG)   printf("Please enter %d activities(name starttime endtime reward):\n", act_cnt);
  for(unsigned int i=0; i<act_cnt; i++){
    fgets(text, TEXT_SIZE-1, stdin);
    // NumOfElements is 4 because input follows "name starttime endtime reward)", 4 items in a row
    str_arr=str_to_str_array(text, SPILTOR, 4);
    
    act_all[i].name=str_arr[0];         // the 1st element is the name of the activity
    act_all[i].strat=(atoi(str_arr[1])-BEGIN_OF_DAY)/100; // devided by 100 cuz HHMM, MM is minutes and it's not used
    act_all[i].end  =(atoi(str_arr[2])-BEGIN_OF_DAY)/100; // devided by 100 cuz HHMM, MM is minutes and it's not used
    act_all[i].reward=atoi(str_arr[3]); // the 3rd element is the reward of the activity
    act_all[i].picked=0;

    // str_arr[0] can't be freed cuz it's assigned to act_all[i].name
    free(str_arr[1]); free(str_arr[2]); free(str_arr[3]);
    free(str_arr);
  }


  // print all the activities
  for(unsigned int i=0; i<act_cnt; i++){
    if(DEBUG)
      printf("No.%d activity, name=%s, %04d~%04d, reward:%d\n", 
        i, 
        act_all[i].name,
        act_all[i].strat*100+BEGIN_OF_DAY,
        act_all[i].end*100+BEGIN_OF_DAY,
        act_all[i].reward);
  }

  // find the best schedule of activities combination
  for(unsigned int i=0; i<act_cnt; i++){
    if(act_all[i].picked==0){
      if(DEBUG)   printf("\nActivity combination:%s ", act_all[i].name);
      act_all[i].picked=1;
      int rewards=act_all[i].reward;

      // clear the schedule for next combination of activities
      memset(schedule, -1, (SCH_SIZE)*sizeof(int));  // -1 means free time
      
      // add the first picked activity to schedule
      for(int t=act_all[i].strat; t<act_all[i].end; t++){
        schedule[t]=i;
      }
      
      // check if the remaining time can fit any activity.
      // if so, add them to schedule
      for(unsigned int j=0; j<act_cnt; j++){
        if( free_to_join(act_all[j], schedule, SCH_SIZE)==1 ){
          if(DEBUG)   printf("%s ", act_all[j].name);
          act_all[j].picked=1;
          rewards+=act_all[j].reward;
          for(int t=act_all[j].strat; t<act_all[j].end; t++)
            schedule[t]=j;  // add act_all[j] to schedule
        }
      }

      if(rewards>max_reward){
        max_reward=rewards;
        memcpy(result_sch, schedule, sizeof(int)*SCH_SIZE);
      }
    }
  }

  // print the best activity combination and its reward
  if(DEBUG){
    printf("\nThe best activity combination and its reward:");
  }
  for(unsigned int i=0; i<act_cnt; i++){
    for(int t=0; t<SCH_SIZE; t++){
      if(result_sch[t]==i){
        printf("%s ", act_all[i].name);
        break;
      }
    }
  }
  printf("%d\n", max_reward);
  fflush(stdout);

  // free the strings: names of activities
  for(unsigned int i=0; i<act_cnt; i++)   free(act_all[i].name);
  free(act_all);
  free(result_sch);
  free(schedule);
  free(text);
  if(DEBUG)
    printf("\n\n\n\nProgram ended. ");
}
