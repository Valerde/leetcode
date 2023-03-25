#include<iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct Node {
	int data;
	struct Node* next;
} node;
void show(node*first) {
	Node *p;
	p=first->next;
	while(p!=NULL) {
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
void buildincre(Node*head,int n) {
	node *p,*cur,*pre;
//	pre = (node *)malloc(sizeof(node));
//    pre->next = NULL;
//	cur = (node *)malloc(sizeof(node));
//    cur->next = NULL;
	cout<<"请输入数据："<<endl;
	for(int i=0; i<n; i++) {
		int data;
		cur=head->next;
		cin>>data;
		p=new Node;
		p->data=data;
		pre=head;
		while(cur!=NULL&&cur->data<=data) {
			pre=cur;
			cur=cur->next;

		}
		p->next=cur;
		pre->next=p;

	}
	show(head);
}


void combine(node*f1,node*f2,node*f3, int n,int m) {
	show(f1);
	show(f2);
	node*p,*q,*res;
	p=f1->next;
	q=f2->next;
	res=f3->next;
	if(f1->next==NULL&&f2->next!=NULL) {
		cout<<"合并后链表为："<<endl;
		show(f2);
		return;
	} else if(f2->next==NULL&&f1->next!=NULL) {
		cout<<"合并后链表为："<<endl;
		show(f1);
		return;
	} else if(f2->next==NULL&&f1->next==NULL) {
		cout<<"合并后链表为空"<<endl;
		return;
	} else {
		int t=0;
		while(t<m+n) {
			while(p!=NULL&&(q==NULL||p->data<=q->data)) {
				node *k;
				k = (node *)malloc(sizeof(node));
				k->next = NULL;
				k->data=p->data;
				if(f3->next!=NULL)
					res->next=k;
				else
					f3->next=k;
				res=k;
				p=p->next;
				t++;
			}
			while(q!=NULL&&(p==NULL||p->data>=q->data)) {
				node *k;
				
				k = (node *)malloc(sizeof(node));
				k->next = NULL;
				k->data=q->data;
				if(f3->next!=NULL)
					res->next=k;
				else
					f3->next=k;
				res=k;
				q=q->next;
				t++;
			}
		}
		cout<<"合并后的链表为："<<endl;
		show(f3);
	}
}
int main(void) {
	node *f1,*f2,*f3;
	f1 = (node *)malloc(sizeof(node));
	f1->next = NULL;
	f2 = (node *)malloc(sizeof(node));
	f2->next = NULL;
	f3 = (node *)malloc(sizeof(node));
	f3->next = NULL;
	int m,n;
	cin>>n;
	cin>>m;

	buildincre(f1,n);
	buildincre(f2,m);
	cout<<"---"<<endl;
	combine(f1,f2,f3,n,m);

}
