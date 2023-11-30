#include<stdio.h>
#include<stdlib.h>
typedef struct Qnode{
	int a;
	struct Qnode *next;
}Qnode,*Quereptr;
typedef struct{
	Quereptr front,rear;
	int len;
}linkquere;

void InitQuere(linkquere *Q){
	Q->front=Q->rear=(Quereptr)malloc(sizeof(Qnode));
	if(Q->front==NULL)
	return;
	Q->front->next==NULL;
	Q->len=0;
} 

void EnQuere(linkquere *Q){
	Quereptr p;
	p=(Quereptr)malloc(sizeof(Qnode));
	if(!p) return;
	printf("输入要入队的数字：");
	scanf("%d",&p->a);
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	Q->len++;
}

void DeQuere(linkquere *Q){
	Quereptr p;
	p=(Quereptr)malloc(sizeof(Qnode));
	if(!p)return ;
    if(Q->len==0)
    printf("队列为空！\n");
    else{
    	p=Q->front->next;
    	printf("输出队头元素为：%d\n",p->a);
    	Q->front->next=p->next;
    	free(p);
    	Q->len--;
    }
} 

void ShowForR(linkquere *Q){
	if(Q->len==0)
	printf("队列为空！\n");
	else{
		printf("队头元素为%d\n",Q->front->next->a);//d队头不存放数字，队尾存放 
		printf("队尾元素为%d\n",Q->rear->a);
	}
}

void ClearQuere(linkquere *Q){
	Quereptr p,po;
	p=(Quereptr)malloc(sizeof(Qnode));
	po=(Quereptr)malloc(sizeof(Qnode));
	if(!p||!po)return;
	Q->rear=Q->front;
	p=Q->front->next;
	while(p){
		po=p;
		p=p->next;
		free(po);
	}
	Q->len=0;
	printf("队列已清空！\n"); 
}

void ShowLen(linkquere *Q){
	printf("队列长度为：%d\n",Q->len);
}

void Qempty(linkquere *Q){
	if(Q->len==0)
	printf("队列为空！\n");
	else printf("队列不为空！\n");
}

void my_print(){
	printf("1->输出队列的长度为\n"
	"2->输出队列首尾元素\n"
	"3->显示队列是否为空\n"
	"4->将一个数字压入队列\n"
	"5->将一个数字弹出队列\n"
	"6->清空队列\n");
}

int main(void){
	linkquere Q;
	InitQuere(&Q);
	my_print();
	int key;
	printf("输入将要进行的操作：");
	scanf("%d",&key);
	while(key){
		switch(key){
			case 1:ShowLen(&Q);break;
			case 2:ShowForR(&Q);break;
			case 3:Qempty(&Q);break;
			case 4:EnQuere(&Q);break;
			case 5:DeQuere(&Q);break;
			case 6:ClearQuere(&Q);break;
			default:printf("无效操作！\n");break;
		}
		printf("\n");
		my_print();
		printf("输入将要进行的操作：");
	    scanf("%d",&key);
	}
}










