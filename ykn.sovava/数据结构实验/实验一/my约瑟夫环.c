#include <stdio.h>
#include<stdlib.h>
typedef struct part{
	union{
		struct{
	     int num;
	     int code;
	   };
	   	int len;
	};
	struct part *next;
}part,*linklist;
linklist create(){
   linklist header = (linklist)malloc(sizeof(part));
    if(header != NULL){
      header->len = 0;
      header->next = header;
    }

    return header; 
} 
int insert(linklist L,int num,int code){
	linklist po,p;
	int n=L->len;
	int i=0;
	po=(linklist)malloc(sizeof(part));
	p=(linklist)malloc(sizeof(part));
	if(po==NULL||p==NULL)   return 0;
	p=L;
	for(;i<L->len;i++,p=p->next);
	po->num=num-1;
	po->code=code;
	po->next=L;
	p->next=po;
	
	L->len++;
}
int myprint(linklist L){
	int i=0;
	linklist po;
	po=(linklist)malloc(sizeof(part));
	if(!po)return 0;
	po=L;
	for(;i<L->len;i++)
	{
		po=po->next;
		printf("第%d个学生密码是%d\n",po->num,po->code);
	}
}
int outlist(linklist L,int *m){
	int i,j,n;
	n=L->len;
	linklist p,po;
	p=(linklist)malloc(sizeof(part));
	po=(linklist)malloc(sizeof(part));
	if(po==NULL||p==NULL)  return 0;
	p=L;
	for(i=0;i<n;i++)
	{
	   for(j=0;j<*m-1;j++){
	   	  p=p->next;
	   	  if(p==L){
	   	  	j--;
	   	  }
	   }
	   
	   po=p->next;
	   if(po==L)
	   {  po=po->next;
	   printf("出列的人序号为%d，密码为%d\n",po->num,po->code);
	   L->next=po->next;
	   }
	   else{
	   	printf("出列的人序号为%d，密码为%d\n",po->num,po->code);
	   p->next=po->next;
	   } 
	   *m=po->code;
	   free(po);
	   L->len--;
	}
}
void main(){
	linklist L =create();
	int num=1,code,m;
	printf("输入第%d个学生的密码：",num);
    num++;
	scanf("%d",&code);
	while(code>0){
	insert(L,num,code);
	printf("输入第%d个学生的密码：",num);
    num++;
	scanf("%d",&code);
    }
    printf("学生编号及密码为：\n");
    myprint(L);
    printf("输入起始密码：");
    scanf("%d",&m);
    printf("出列的学生编号及密码为：\n");
    outlist(L,&m);
}
