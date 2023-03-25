#include<iostream>
using namespace std;
typedef struct Node {
	int data;
	struct Node* next;
} node;
void show(Node*first) {
	Node *p;
	p=first->next;
	while(p!=NULL) {
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
void buildincre(Node*head,int n) {
	Node *p,*cur,*pre;
	cout<<"请输入数据："<<endl;
	for(int i=0; i<n; i++) {
		int data;
		cur = head;
		pre = head;
		cin>>data;
		p=new Node;
		p->data=data;
		cout<<p->next;
		if(head->next == NULL) {
			head->next = p;
			cur = cur->next;
		} else {
			while(cur!=NULL&&cur->data<data) {
				pre=cur;
				cur=cur->next;

			}
			p->next=cur;
			pre->next=p;
		}

	}
	show(head);
}

void combine(Node*f1,Node*f2,Node*f3, int n,int m) {
	Node*p,*q,*res;
	p=f1->next;
	q=f2->next;
	res=f3->next;
	if(f1->next==NULL&&f2->next!=NULL) {
		cout<<"合并后链表为："<<endl;
		show(f2);
	} else if(f2->next==NULL&&f1->next!=NULL) {
		cout<<"合并后链表为："<<endl;
		show(f1);
	} else if(f2->next==NULL&&f1->next==NULL)
		cout<<"合并后链表为空"<<endl;
	else {
		int t=0;
		while(t<m+n) {
			while(p!=NULL&&(q==NULL||p->data<=q->data)) {
				Node *k=new Node;
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
				Node *k=new Node;
				k->data=q->data;
				if(f2->next!=NULL)
					res->next=k;
				else
					f2->next=k;
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
	Node *f1,*f2,*f3;
	int m,n;
	cin>>n;
	cin>>m;

	buildincre(f1,n);
	buildincre(f1,m);
	combine(f1,f2,f3,n,m);

}
