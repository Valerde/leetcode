#include<stdio.h>
//#include<stdlib.h>
typedef struct StackNode{
	int paizhao;
	int shijian;
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

void pop(linkstack *S,int *paizhao,int *shijian){
	linkstackptr p,po,pi;
	pi=(linkstackptr)malloc(sizeof(StackNode));
	p=(linkstackptr)malloc(sizeof(StackNode));
	po=(linkstackptr)malloc(sizeof(StackNode));
	if(p==NULL||po==NULL||pi==NULL){
		printf("��ÿռ�ʧ�ܣ�\n");
		return ; 
	}
	if(S->top==NULL)
	{  printf("ջΪ��\n");
	return ;
	}
	p=S->top;
	*paizhao=p->paizhao;
	*shijian=p->shijian;
	if(S->count==1){
		S->top==NULL;
	}
	else{
	po=p->next;
	S->top=po;
	free(p);}
	S->count--;
}

void push(linkstack *S,int paizhao,int shijian){
	linkstackptr p;
	p=(linkstackptr)malloc(sizeof(StackNode));
	if(!p){
	printf("��ȡ�ռ�ʧ�ܣ�\n");
	return;
    }
	p->paizhao=paizhao;
	p->shijian=shijian;
	int a=0;
	a=p->paizhao;
	p->next=S->top;
	S->top=p;
	S->count++; 
}

typedef struct Qnode{
	int paizhao;
	int shijian;
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
	printf("����Ҫ��ӵĳ������뼰ʱ�䣺");
	scanf("%d %d",&p->paizhao,&p->shijian);
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	Q->len++;
}

void DeQuere(linkquere *Q,int *paizhao,int *shijian){
	Quereptr p;
	p=(Quereptr)malloc(sizeof(Qnode));
	if(!p)return ;
    if(Q->len==0)
    printf("���Ϊ�գ�\n");
    else{
    	p=Q->front->next;
    	*paizhao=p->paizhao;
    	*shijian=p->shijian;
    	Q->front->next=p->next;
    	free(p);
    	Q->len--;
    }
} 

int Qempty(linkquere *Q){
	if(Q->len==0)
	return 0;
	else return 1;
}

int topnumber(linkstack *S){
	if(!S->count){
		return -1;
	}
	else{
	return S->top->paizhao;
	}
}

void OutParking(linkstack *parting,linkquere *biandao){
	int shijian,paizhao;
	int pai,shi;
	linkstack fuzhu;
	initstack(&fuzhu);
	printf("����Ҫ�˳��ĳ��ƺż�ʱ�䣺");
	scanf("%d %d",&paizhao,&shijian);
	linkstackptr p;
	p=(linkstackptr)malloc(sizeof(StackNode));
	int topnum;
	topnum=topnumber(parting);
	if(topnum==-1){
	printf("��ǰͣ�����޳���\n");
	return;}
	while(topnum!=paizhao&&topnum!=-1){
		pop(parting,&pai,&shi);
		push(&fuzhu,pai,shi);
		topnum=topnumber(parting);
	}
	int index=1;
	if(topnum==-1){
		printf("�޵�ǰ������\n");
		index=0;
	}else{
		pop(parting,&pai,&shi);
	    printf("����Ϊ%d�ĳ���ͣ��ʱ��Ϊ%d\n",pai,shijian-shi);
	}
	topnum=topnumber(&fuzhu);
	while(topnum!=-1){
	    pop(&fuzhu,&pai,&shi);
		push(parting,pai,shi);
		topnum=topnumber(&fuzhu);
	}
	if(index&&Qempty(biandao)){
		DeQuere(biandao,&pai,&shi);
		push(parting,pai,shi);
	}
}

int stacklenth(linkstack *S){
	return S->count;
}

void my_print(){
	printf("A->ĳһ����������\n"
	"D->ĳһ�����뿪\n"
	"E->����\n"
	);
}

int main(void){
	int maxplace=2;
	linkstack parting;
	initstack(&parting);
	linkquere biandao;
	InitQuere(&biandao);
	my_print();
	char key;
	printf("���뽫Ҫ���еĲ�����");
	scanf(" %c",&key);
	while(key){
		switch(key){
			case 'A':{
				if(stacklenth(&parting)<maxplace){
					int paizhao,shijian;
                	printf("����Ҫ����ĳ��ƺż�ʱ�䣺");
                	scanf("%d %d",&paizhao,&shijian);
                	push(&parting,paizhao,shijian);
				}
				else{
					EnQuere(&biandao); 
				}
				break;
			}
			case 'D':OutParking(&parting,&biandao);break;
			case 'E':return 0;
			default:printf("��Ч����!\n");break;
		}
		printf("\n");
		my_print();
		printf("���뽫Ҫ���еĲ�����");
	    scanf(" %c",&key);
	}
}











