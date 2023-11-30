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
		printf("��ÿռ�ʧ�ܣ�\n");
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
		printf("��ÿռ�ʧ�ܣ�\n");
		return 0; 
	}
	if(S->top==NULL)
	{  printf("ջΪ��\n");
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
	printf("��ȡ�ռ�ʧ�ܣ�\n");
	return;
	}
    p->a=num;
	p->next=S->top;
	S->top=p;
	S->count++; 
}

void PushAll(linkstack *S){
	long number;
	printf("����һ��ʮ���Ƶ�����\n");
	scanf("%ld",&number);
	int a;
	while(number){
		a=number%8;
		number/=8;
		push(S,a);       //??????ָ�뻹�ÿ��������� 
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
	printf("�Ƿ����ת����0->��\n");
	scanf("%d",&an);
    while(an){
	   PushAll(&S);
	   printf("ת��Ϊ�˽���Ϊ��");
	   bn=stacklenth(&S);
	   while(bn){
	      pop(&S);
		  bn=stacklenth(&S);
	   } 
	   printf("\n\n");
	   clearstack(&S);
	   printf("�Ƿ����ת����0->��\n");
	   scanf("%d",&an);
	}
}







