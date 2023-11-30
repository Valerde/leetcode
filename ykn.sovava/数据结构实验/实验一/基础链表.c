#include<stdio.h> 
#include<stdlib.h>
void myprintf();
void insert();
void Delete();
void find();
void printflist();
typedef struct {
	int num;
	struct part *next;
}part,*linklist;
linklist first = NULL;
void main(){
	char key;
	myprintf();
	printf("enter the key:");
	key=getchar();
	while(key){
		switch(key){
			case 'i':insert();break;
			case 'd':Delete();break;
			case 'f':find();break;
			case 'p':printflist();break;
			default:printf("wrong key!");break;
		}
		myprintf();
		printf("enter the key: ");
		getchar();
		key=getchar();
	}
}
void insert(){
	linklist p1,p;
	p1=(linklist )malloc(sizeof(part));
	printf("Enter number:");
	scanf("%d",&p1->num);
	if(first==NULL) {first=p1;first->next=NULL;}
	else{
		p1->next=first;
		first=p1;
	}
	printf("\n");
} 
void Delete(){
	int a;
	linklist prev,cur;
	printf("Enter the number that you want to delete: ");
	scanf("%d",&a);
    for(cur=first,prev=NULL;cur!=NULL&&a!=cur->num;prev=cur,cur=cur->next);
	if(!cur){printf("not find\n");return ;}
    else if(prev==NULL){first=cur->next;free(cur);return ;}
	else {prev->next=cur->next;free(cur);return;}
	printf("\n");
}
void find(){
	int a,i=1;
	linklist p;
	printf("Enter the number that you want to find ");
	scanf("%d",&a);
	for(p=first;p->num!=a&&p!=NULL;p=p->next,i++);
	if(p==NULL) printf("no find!\n");
	else printf("the number %d place is %d \n",a,i);
	printf("\n");
}
void printflist(){
	linklist p;
	p=first;
	while(p){
		printf("%d\t",p->num);
		p=p->next;
	}
	printf("\n\n");
}
void myprintf(){
	printf("Entering 'i' means insert\n"
	"Entering 'd' means delete\n"
	"Entering 'f' means find\n"
	"Entering 'p' means print\n\n");
}
