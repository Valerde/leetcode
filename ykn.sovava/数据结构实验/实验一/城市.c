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
       printf("请输入需要查找的城市名：");
       scanf(" %c",&name);
       while(p){
        if(p->data.Cname==name)
           {
		   printf("该城市的坐标为：%g,%g\n",p->data.x,p->data.y);
		   index=1;
		   }
           p=p->next;
       }
       if(index==0)
	   printf("无此城市\n");
}
void Insert(){
       City p=L;
       City s=(City)malloc(sizeof(CityNode));
       printf("请输入要插入的城市名及它的坐标:");
       scanf(" %c %g %g",&s->data.Cname,&s->data.x,&s->data.y);
       s->next=p->next;
       p->next=s;
       printf("新城市%c插入成功\n",s->data.Cname);
}
void Delete(){
	
    City q,p=L;
    int j=0;
    char z;
    printf("请输入要删除的城市名：");
    scanf(" %c",&z);
    while(p->data.Cname!=z&&p->next!=NULL){
       q=p;
       p=p->next;
    }if(p->next==NULL){
    printf("无城市\n");
    return;}
    q->next=p->next;
    free(p);
    printf("删除成功！\n");
	}
void distance(){
    float s,r;
    float x1,y1,x2,y2;
    City p;
    p=L->next;
    printf("请输入中心坐标x y:");
    scanf(" %f %f",&x1,&y1);
    printf("请输入与中心城市的距离范围:");
    scanf(" %f",&r);
    while(p){
	   x2=p->data.x;
       y2=p->data.y;
       s=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
       if(s<r){
         printf("与(%g %g)的中心城市的距离小于等于%g的城市有：\n",x1,y1,r);
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
       printf("请输入旧的城市名：");
       scanf(" %c",&a);
       while(p->data.Cname!=a&&p->next!=NULL)
       {
        p=p->next;
       }
       if(p->next==NULL){
       	printf("无此城市\n");
       	return;
       }
    printf("请输入新的城市名：");
       scanf(" %c",&b);
       printf("请输入新的城市坐标：");
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
    printf("  请选择需要操作的功能：          \n");
    printf("  1->输出全部城市信息\n");
    printf("  2->查找\n");
    printf("  3->插入\n");
    printf("  4->删除\n");
    printf("  5->修改\n");
    printf("  6->与坐标x y距离小于r的城市\n");
    printf("  0->结束\n");
    printf("\n");
    printf("请输入您选择的功能号：");
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
