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
    printf("����գ�\n");
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
	printf("��ջΪ��%d\n",S->top->a);
	po=p->next;
	S->top=po;
	free(p);
	S->count--;
}
void push(linkstack *S){
	linkstackptr p;
	p=(linkstackptr)malloc(sizeof(StackNode));
	if(!p){
	printf("��ȡ�ռ�ʧ�ܣ�\n");
	return;
    }
	printf("������ջ�����֣�");
	scanf("%d",&p->a);
	p->next=S->top;
	S->top=p;
	S->count++; 
}
void topnumber(linkstack *S){
	if(!S->count){
		printf("ջΪ�գ�\n");
	}
	else{
		printf("ջ��Ԫ��Ϊ��%d\n",S->top->a);
	}
}
void stackempty(linkstack *S){
	if(S->count==0)
	printf("ջΪ�գ�\n");
	else
	printf("ջ��Ϊ��\n");
}
void stacklenth(linkstack *S){
	printf("ջ�ĳ���Ϊ��%d\n",S->count);
}
void my_print(){
	printf("1->���ջ�ĳ���Ϊ\n"
	"2->���ջ��Ԫ��\n"
	"3->���ջ�Ƿ�Ϊ��\n"
	"4->��һ������ѹ��ջ\n"
	"5->��һ�����ֵ���ջ\n"
	"6->���ջ\n");
}
int main(void){
	linkstack S;
	initstack(&S);
	my_print();
	int key;
	printf("���뽫Ҫ���еĲ�����");
	scanf("%d",&key);
	while(key){
		switch(key){
			case 1:stacklenth(&S);break;
			case 2:topnumber(&S);break;
			case 3:stackempty(&S);break;
			case 4:push(&S);break;
			case 5:pop(&S);break;
			case 6:clearstack(&S);break;
			default:printf("��Ч����!\n");break;
		}
		printf("\n");
		my_print();
		printf("���뽫Ҫ���еĲ�����");
	    scanf("%d",&key);
	}
}













