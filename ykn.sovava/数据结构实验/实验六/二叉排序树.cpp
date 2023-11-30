#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode, *BiTree;


void InsertTree(BiTree *T, int e) {
    BiTree p = NULL;
    if (!SearchTree((*T), e, NULL, &p)) {
        BiTree s = (BiTree)malloc(sizeof(BiTNode));
        s->data = e;
        s->lchild = s->rchild = NULL;
        if (!p) {
            *T = s;
        }
        else if (e < p->data) {
            p->lchild = s;
        }
        else {
            p->rchild = s;
        }
    }
}

void Delete(BiTree *p)
{
    BiTree q, s;
    if (!(*p)->lchild && !(*p)->rchild) {
        *p = NULL;free(*p);
    }
    else if (!(*p)->lchild) {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else if (!(*p)->rchild) {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    else {
        q = *p;
        s = (*p)->lchild;
        while (s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data;
        if (q != *p) {
            q->rchild = s->lchild;
        }
        else {
            q->lchild = s->lchild;
        }
        free(s);
    }
}
void DeleteTree(BiTree *T, int key)
{
    if (!(*T)) {
        return ;
    }
    else
    {
        if (key == (*T)->data) {
            Delete(T);
        }
        else if (key < (*T)->data) {
            DeleteTree(&(*T)->lchild, key);
        }
        else {
            DeleteTree(&(*T)->rchild, key);
        }
    }
}
void in_order(BiTree T)
{
    if (T==NULL) {
        return;
    }
    in_order(T->lchild);
    printf("%d ", T->data);
    in_order(T->rchild);
}
int find(BiTree T,int *count){
	int a,index=0;
	printf("����Ҫ���ҵ����֣�");
	scanf("%d",&a);
	while(T){
		(*count)++;
		if(a==T->data){
			index=1;
		return 1;}
		else if(a>T->data) 
		T=T->rchild;
		else 
		T=T->lchild;
	}
	if(index==0)return 0;
}
void print(){
	printf("\n1->�������\n"
	 
	"2->����һ������\n"
	"3->ɾ��һ������\n"
	"4->����һ������\n"
	"0->����\n"
	"����Ҫ���еĲ���\n\n");
}

int main()
{
    int i,n=10,count=0,re=0;
    int a[10];
    printf("����ʮ��������\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]); 
    BiTree T=NULL;
    for (i = 0; i <n; i++) {
        InsertTree(&T, a[i]);
    }
    printf("�Ѵ洢��ʮ������\n");
    print();
    int key;
    scanf("%d",&key);
    while(key){
    	switch(key){
    		case 1:in_order(T);break;
    		case 2:printf("����Ҫ��������֣�");scanf("%d",&i);InsertTree(&T,i);break;
    		case 3:printf("����ɾ��������\n");scanf("%d",&i); DeleteTree(&T,i);break;
    		case 4:re=find(T,&count);if(re)printf("�Ѿ��ҵ������ҳ���Ϊ%d \n",count);else printf("δ�ҵ������֣�\n");count=0;break;
			case 0:return 0;
    		default:break;
    	}
    	print();
    	scanf("%d",&key);
    }
}
