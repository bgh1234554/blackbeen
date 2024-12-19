#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct address {
  char name[21]; //이름
  char number[16]; // 전화번호
  char birthday[9]; // 생일
}; //구조체 선언

struct address ad[100];

void sort(int count){
  for(int j=0;j<count;j++){
    for(int i=0;i<count-1;i++){
      if(strcmp(ad[i].name,ad[i+1].name)==1){
        struct address tmp = ad[i];
        ad[i] = ad[i+1];
        ad[i+1] = tmp;
      }
    }
  }  
}

int main(){
  int count = 0;
  while(1){
    printf("*****Menu*****\n");
    printf("1. Registration, 2. ShowAll, 3. Delete, 4. FindByBirth, 5. Exit\n");
    printf("Enter the menu number:");
    int x; scanf("%d", &x);
    if(x==1){
      char Name[21]; char Number[16]; char Birthday[9];
      printf("Name:");  // 고정
      scanf("%s",Name);
      printf("Phone number:"); // 고정
      scanf("%s",Number);
      printf("Birth:"); //고정
      scanf("%s",Birthday);
      if(count>100){
        printf("Overflow\n");
      }
      else{
        for(int i=0;i<21;i++){
          ad[count].name[i]=Name[i];
        }
        for(int i=0;i<16;i++){
          ad[count].number[i]=Number[i];
        }
        for(int i=0;i<9;i++){
          ad[count].birthday[i]=Birthday[i];
        }
        printf("count: %d\n",count+1);
        count += 1;                 
      }
      sort(count);
    }
    else if(x==2){
      for(int i=0;i<count;i++){
        printf("%s %s %s\n",ad[i].name,ad[i].number,ad[i].birthday);
      }
    }
    else if(x==3){
      int names = 0; char nametofind[21];
      printf("Name:");  // 고정
      scanf("%s",nametofind);
      for(int i=0;i<count;i++){
        if(strcmp(ad[i].name,nametofind)==0){
          names+=1;
          strcpy(ad[i].name,"");
          strcpy(ad[i].number,"");
          strcpy(ad[i].birthday,"");
        }
      }
      if(names==0){
        printf("No record founded.\n");
      }
      for(int i=1;i<count;i++){
        if(strcmp(ad[i-1].name,"")==0 && strcmp(ad[i].name,"")!=0){
          ad[i-1]=ad[i];
          strcpy(ad[i].name,"");
          strcpy(ad[i].number,"");
          strcpy(ad[i].birthday,"");
        }
      }
      count-=names;
    }
    else if(x==4){
      char birth[3];
      printf("Birth:");  // 고정
      scanf("%s", birth);
      for(int i=0;i<count;i++){
        if(strlen(birth)==2 && ad[i].birthday[4]==birth[0]&&ad[i].birthday[5]==birth[1]){
          printf("%s %s %s\n",ad[i].name,ad[i].number,ad[i].birthday);
        }
        else if(strlen(birth)==1 && ad[i].birthday[4]=='0'&&ad[i].birthday[5]==birth[0]){
          printf("%s %s %s\n",ad[i].name,ad[i].number,ad[i].birthday);
        }
      }
    }
    else if(x==5){
      break;
    }
  }
}

