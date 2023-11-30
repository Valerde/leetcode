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
    printf("已清空！\n");
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
	printf("弹栈为：%d\n",S->top->a);
	po=p->next;
	S->top=po;
	free(p);
	S->count--;
}
void push(linkstack *S){
	linkstackptr p;
	p=(linkstackptr)malloc(sizeof(StackNode));
	if(!p){
	printf("获取空间失败！\n");
	return;
    }
	printf("输入入栈的数字：");
	scanf("%d",&p->a);
	p->next=S->top;
	S->top=p;
	S->count++; 
}
void topnumber(linkstack *S){
	if(!S->count){
		printf("栈为空！\n");
	}
	else{
		printf("栈顶元素为：%d\n",S->top->a);
	}
}
void stackempty(linkstack *S){
	if(S->count==0)
	printf("栈为空！\n");
	else
	printf("栈不为空\n");
}
void stacklenth(linkstack *S){
	printf("栈的长度为：%d\n",S->count);
}
void my_print(){
	printf("1->输出栈的长度为\n"
	"2->输出栈顶元素\n"
	"3->输出栈是否为空\n"
	"4->将一个数字压入栈\n"
	"5->将一个数字弹出栈\n"
	"6->清空栈\n");
}
int main(void){
	linkstack S;
	initstack(&S);
	my_print();
	int key;
	printf("输入将要进行的操作：");
	scanf("%d",&key);
	while(key){
		switch(key){
			case 1:stacklenth(&S);break;
			case 2:topnumber(&S);break;
			case 3:stackempty(&S);break;
			case 4:push(&S);break;
			case 5:pop(&S);break;
			case 6:clearstack(&S);break;
			default:printf("无效操作!\n");break;
		}
		printf("\n");
		my_print();
		printf("输入将要进行的操作：");
	    scanf("%d",&key);
	}
}













