#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    char name[10];
    char phonenumber[20];
    char mobilenumber[20];
    char email[20];
    struct part *next;
}part,*partlist;
void print(){
	 printf("1->插入一个新的信息\n"
    "2->完整打印电话本\n"
    "3->根据名字查询信息\n"
    "其他数字退出\n"
    "输入要进行的功能:");
} 
void main(){
    FILE *fp;
    partlist head,p1,p2;
    char search_name[40],ul,key;
    int index1=0,index2=0;
    if((fp=fopen("phonebook.txt","r+"))==NULL)
    {printf("打开文件失败!\n");exit(0);}
     print(); 
    scanf("%c%c",&key,&ul);
    while(key){
    if(key=='1'){
       printf("#表示结束插入\n");
       p1=p2=(partlist)malloc(sizeof(part));
       head=p1;
       head->next=NULL;
       do{
         printf("输入名字：");
         gets(p1->name);
         if(strcmp(p1->name,"#")==0) break;
         printf("输入固定电话号码：");
         gets(p1->phonenumber);
         if(strcmp(p1->phonenumber,"#")==0) break;
         printf("输入移动电话号码：");
         gets(p1->mobilenumber);
         if(strcmp(p1->mobilenumber,"#")==0) break;
         printf("输入邮箱：");
         gets(p1->email);
         if(strcmp(p1->email,"#")==0) break;
         if(fwrite(p1,sizeof(part),1,fp)==0) index1=1;
         p1=(partlist)malloc(sizeof(part));
         p2->next=p1;
         p2=p1;
       }while(1);
       fclose(fp);
       printf("已结束输入\n");
       if(index1==1) printf("写入文件失败\n");
    }
    else if(key=='2'){
    	if((fp=fopen("phonebook.txt","r+"))==NULL)
    {printf("打开文件失败\n");exit(0);}
       printf("名字\t固话\t移话\t邮箱\n");
       p1=(partlist)malloc(sizeof(part));
       while(!feof(fp)){
         if(fread(p1,sizeof(part),1,fp))
         printf("%s\t%s\t%s\t%s\n",p1->name,p1->phonenumber,p1->mobilenumber,p1->email);
         }
	   free(p1);
    }
    else if(key=='3'){
      if((fp=fopen("phonebook.txt","r+"))==NULL)
      {printf("打开文件错误\n");exit(0);}
      printf("输入要查询的名字:");
      gets(search_name);
      p1=(partlist)malloc(sizeof(part));
      while(!feof(fp)){
      if(fread(p1,sizeof(part),1,fp))
        if(strcmp(p1->name,search_name)==0){
           printf("名字\t固话\t移话\t邮箱\n");
           printf("%s\t%s\t%s\t%s\n",p1->name,p1->phonenumber,p1->mobilenumber,p1->email);
           index2=1;
        }
      }
      if(index2!=1)
      printf("没有找到\n");
      free(p1);
    }
    else exit(0);
   print();
    scanf("%c%c",&key,&ul);
	}
}
