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
	printf("����Ҫ��ӵ����֣�");
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
    printf("����Ϊ�գ�\n");
    else{
    	p=Q->front->next;
    	printf("�����ͷԪ��Ϊ��%d\n",p->a);
    	Q->front->next=p->next;
    	free(p);
    	Q->len--;
    }
} 

void ShowForR(linkquere *Q){
	if(Q->len==0)
	printf("����Ϊ�գ�\n");
	else{
		printf("��ͷԪ��Ϊ%d\n",Q->front->next->a);//d��ͷ��������֣���β��� 
		printf("��βԪ��Ϊ%d\n",Q->rear->a);
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
	printf("��������գ�\n"); 
}

void ShowLen(linkquere *Q){
	printf("���г���Ϊ��%d\n",Q->len);
}

void Qempty(linkquere *Q){
	if(Q->len==0)
	printf("����Ϊ�գ�\n");
	else printf("���в�Ϊ�գ�\n");
}

void my_print(){
	printf("1->������еĳ���Ϊ\n"
	"2->���������βԪ��\n"
	"3->��ʾ�����Ƿ�Ϊ��\n"
	"4->��һ������ѹ�����\n"
	"5->��һ�����ֵ�������\n"
	"6->��ն���\n");
}

int main(void){
	linkquere Q;
	InitQuere(&Q);
	my_print();
	int key;
	printf("���뽫Ҫ���еĲ�����");
	scanf("%d",&key);
	while(key){
		switch(key){
			case 1:ShowLen(&Q);break;
			case 2:ShowForR(&Q);break;
			case 3:Qempty(&Q);break;
			case 4:EnQuere(&Q);break;
			case 5:DeQuere(&Q);break;
			case 6:ClearQuere(&Q);break;
			default:printf("��Ч������\n");break;
		}
		printf("\n");
		my_print();
		printf("���뽫Ҫ���еĲ�����");
	    scanf("%d",&key);
	}
}










