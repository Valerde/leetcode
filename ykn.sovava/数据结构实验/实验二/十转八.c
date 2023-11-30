#include<stdio.h>
#include<stdlib.h>
typedef struct StackNode{
	int a;
	struct StackNode *next;
}StackNode,*linkstackptr;
typedef struct {
	linkstackptr top;
	int count;
}linkstack;
void initstack(linkstack *S){
	S->top=(linkstackptr)malloc(sizeof(StackNode));
	if(!S->top){
		return;
	}
	S->top=NULL;
	S->count=0;
}  

int clearstack(linkstack *S){
	linkstackptr p,po;
	p=(linkstackptr)malloc(sizeof(StackNode));
	po=(linkstackptr)malloc(sizeof(StackNode));
	if(p==NULL||po==NULL){
		printf("获得空间失败！\n");
		return 0; 
	}
	p=S->top;
	while(p){
		po=p;
		p=p->next;
		free(po);
	}
    S->count=0;
}

int pop(linkstack *S){
	linkstackptr p,po;
	p=(linkstackptr)malloc(sizeof(StackNode));
	po=(linkstackptr)malloc(sizeof(StackNode));
	if(p==NULL||po==NULL){
		printf("获得空间失败！\n");
		return 0; 
	}
	if(S->top==NULL)
	{  printf("栈为空\n");
	return 0;
	}
	p=S->top;
	printf("%d",S->top->a);
	po=p->next;
	S->top=po;
	free(p);
	S->count--;
}

void push(linkstack *S,int num){
	linkstackptr p;
	p=(linkstackptr)malloc(sizeof(StackNode));
	if(!p){
	printf("获取空间失败！\n");
	return;
	}
    p->a=num;
	p->next=S->top;
	S->top=p;
	S->count++; 
}

void PushAll(linkstack *S){
	long number;
	printf("输入一个十进制的数：\n");
	scanf("%ld",&number);
	int a;
	while(number){
		a=number%8;
		number/=8;
		push(S,a);       //??????指针还得看！！！！ 
	}
}

int stacklenth(linkstack *S){
	int am;
	am=S->count;
	return am;
}

int main (void){
	linkstack S;
	initstack(&S);
	int bn,an;
	printf("是否进行转换？0->否\n");
	scanf("%d",&an);
    while(an){
	   PushAll(&S);
	   printf("转换为八进制为：");
	   bn=stacklenth(&S);
	   while(bn){
	      pop(&S);
		  bn=stacklenth(&S);
	   } 
	   printf("\n\n");
	   clearstack(&S);
	   printf("是否进行转换？0->否\n");
	   scanf("%d",&an);
	}
}







