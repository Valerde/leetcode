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
	 printf("1->����һ���µ���Ϣ\n"
    "2->������ӡ�绰��\n"
    "3->�������ֲ�ѯ��Ϣ\n"
    "���������˳�\n"
    "����Ҫ���еĹ���:");
} 
void main(){
    FILE *fp;
    partlist head,p1,p2;
    char search_name[40],ul,key;
    int index1=0,index2=0;
    if((fp=fopen("phonebook.txt","r+"))==NULL)
    {printf("���ļ�ʧ��!\n");exit(0);}
     print(); 
    scanf("%c%c",&key,&ul);
    while(key){
    if(key=='1'){
       printf("#��ʾ��������\n");
       p1=p2=(partlist)malloc(sizeof(part));
       head=p1;
       head->next=NULL;
       do{
         printf("�������֣�");
         gets(p1->name);
         if(strcmp(p1->name,"#")==0) break;
         printf("����̶��绰���룺");
         gets(p1->phonenumber);
         if(strcmp(p1->phonenumber,"#")==0) break;
         printf("�����ƶ��绰���룺");
         gets(p1->mobilenumber);
         if(strcmp(p1->mobilenumber,"#")==0) break;
         printf("�������䣺");
         gets(p1->email);
         if(strcmp(p1->email,"#")==0) break;
         if(fwrite(p1,sizeof(part),1,fp)==0) index1=1;
         p1=(partlist)malloc(sizeof(part));
         p2->next=p1;
         p2=p1;
       }while(1);
       fclose(fp);
       printf("�ѽ�������\n");
       if(index1==1) printf("д���ļ�ʧ��\n");
    }
    else if(key=='2'){
    	if((fp=fopen("phonebook.txt","r+"))==NULL)
    {printf("���ļ�ʧ��\n");exit(0);}
       printf("����\t�̻�\t�ƻ�\t����\n");
       p1=(partlist)malloc(sizeof(part));
       while(!feof(fp)){
         if(fread(p1,sizeof(part),1,fp))
         printf("%s\t%s\t%s\t%s\n",p1->name,p1->phonenumber,p1->mobilenumber,p1->email);
         }
	   free(p1);
    }
    else if(key=='3'){
      if((fp=fopen("phonebook.txt","r+"))==NULL)
      {printf("���ļ�����\n");exit(0);}
      printf("����Ҫ��ѯ������:");
      gets(search_name);
      p1=(partlist)malloc(sizeof(part));
      while(!feof(fp)){
      if(fread(p1,sizeof(part),1,fp))
        if(strcmp(p1->name,search_name)==0){
           printf("����\t�̻�\t�ƻ�\t����\n");
           printf("%s\t%s\t%s\t%s\n",p1->name,p1->phonenumber,p1->mobilenumber,p1->email);
           index2=1;
        }
      }
      if(index2!=1)
      printf("û���ҵ�\n");
      free(p1);
    }
    else exit(0);
   print();
    scanf("%c%c",&key,&ul);
	}
}
