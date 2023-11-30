#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef int status;
typedef struct data{
      char Cname;
      float x;
      float y;
}data;
typedef struct CityNode{
       data data;
       struct CityNode *next;
}CityNode,*City; 

City L; 

City CreateList(){
       int i;
       City p;
       L=(City )malloc(sizeof(CityNode));
       L->next=NULL;
       return L;
}
void search(){
       char name;
       int index=0;
       City p;
       p=L->next;
       printf("��������Ҫ���ҵĳ�������");
       scanf(" %c",&name);
       while(p){
        if(p->data.Cname==name)
           {
		   printf("�ó��е�����Ϊ��%g,%g\n",p->data.x,p->data.y);
		   index=1;
		   }
           p=p->next;
       }
       if(index==0)
	   printf("�޴˳���\n");
}
void Insert(){
       City p=L;
       City s=(City)malloc(sizeof(CityNode));
       printf("������Ҫ����ĳ���������������:");
       scanf(" %c %g %g",&s->data.Cname,&s->data.x,&s->data.y);
       s->next=p->next;
       p->next=s;
       printf("�³���%c����ɹ�\n",s->data.Cname);
}
void Delete(){
	
    City q,p=L;
    int j=0;
    char z;
    printf("������Ҫɾ���ĳ�������");
    scanf(" %c",&z);
    while(p->data.Cname!=z&&p->next!=NULL){
       q=p;
       p=p->next;
    }if(p->next==NULL){
    printf("�޳���\n");
    return;}
    q->next=p->next;
    free(p);
    printf("ɾ���ɹ���\n");
	}
void distance(){
    float s,r;
    float x1,y1,x2,y2;
    City p;
    p=L->next;
    printf("��������������x y:");
    scanf(" %f %f",&x1,&y1);
    printf("�����������ĳ��еľ��뷶Χ:");
    scanf(" %f",&r);
    while(p){
	   x2=p->data.x;
       y2=p->data.y;
       s=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
       if(s<r){
         printf("��(%g %g)�����ĳ��еľ���С�ڵ���%g�ĳ����У�\n",x1,y1,r);
         printf("%c %g %g\n",p->data.Cname,x2,y2);
       }
    p=p->next;
    }
}

void update(){

       char a,b;
       float m,n;
       int k=0;
       City p=L;
       printf("������ɵĳ�������");
       scanf(" %c",&a);
       while(p->data.Cname!=a&&p->next!=NULL)
       {
        p=p->next;
       }
       if(p->next==NULL){
       	printf("�޴˳���\n");
       	return;
       }
    printf("�������µĳ�������");
       scanf(" %c",&b);
       printf("�������µĳ������꣺");
    scanf("%g %g",&m,&n);
       p->data.Cname=b;
       p->data.x=m;
       p->data.y=n;
}
void printall(){
       City a;
       a=L->next;
       while(a)
       {
	   printf("%c  %g %g\n",a->data.Cname,a->data.x,a->data.y);
       a=a->next;}
 }
 void myprint(){
    printf("  ��ѡ����Ҫ�����Ĺ��ܣ�          \n");
    printf("  1->���ȫ��������Ϣ\n");
    printf("  2->����\n");
    printf("  3->����\n");
    printf("  4->ɾ��\n");
    printf("  5->�޸�\n");
    printf("  6->������x y����С��r�ĳ���\n");
    printf("  0->����\n");
    printf("\n");
    printf("��������ѡ��Ĺ��ܺţ�");
 }

void main(){
    CreateList();
    int key;
	myprint();
	scanf(" %d",&key);
	while(key){
		switch(key){
			case 1:printall();break;
            case 2:search();break;
            case 3:Insert();break;
            case 4:Delete();break;
            case 5:update();break;
            case 6:distance();break;
            case 0:break;
			default:printf("wrong key!\n");break;
		}
		printf("\n");
		myprint();
	    scanf(" %d",&key);
	}
}
