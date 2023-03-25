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
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// ʹ��new�����ڴ�����ڴ�й©
void buildincre(Node*head,int n) {
    cout << "���������ݣ�" << endl;
    for (int i=0; i<n; i++) {
        int data;
        Node* cur = head->next;
        Node* p = new Node;  // ʹ��new�����ڴ�
        p->next = NULL;
        cin >> data;
        p->data=data;
        Node* pre=head;
        while (cur!=NULL && cur->data<=data) {
            pre = cur;
            cur = cur->next;
        }
        p->next = cur;
        pre->next=p;
    }
    show(head);
}

void combine(node* f1, node* f2, node* f3, int n, int m) {
    show(f1);
    show(f2);

    Node*p=f1->next, *q=f2->next, *res=f3;
    if(f1->next==NULL && f2->next!=NULL) {
        cout<<"�ϲ�������Ϊ��"<<endl;
        show(f2);
        return;
    } else if(f2->next==NULL && f1->next!=NULL) {
        cout<<"�ϲ�������Ϊ��"<<endl;
        show(f1);
        return;
    } else if(f2->next==NULL && f1->next==NULL) {
        cout<<"�ϲ�������Ϊ��"<<endl;
        return;
    } else {
        while(p!=NULL || q!=NULL) {
            if(p!=NULL && (q==NULL || p->data<=q->data)) {
                Node* k = new Node;  // ʹ��new�����ڴ�
                k->next = NULL;
                k->data = p->data;
                res->next = k;
                res = k;
                p = p->next;
            } else {
                Node* k = new Node;  // ʹ��new�����ڴ�
                k->next = NULL;
                k->data = q->data;
                res->next = k;
                res = k;
                q = q->next;
            }
        }
        cout<<"�ϲ��������Ϊ��"<<endl;
        show(f3->next);
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    node* f1 = new node; f1->next = NULL;
    node* f2 = new node; f2->next = NULL;
    node* f3 = new node; f3->next = NULL;

    buildincre(f1, n);
    buildincre(f2, m);
    cout<<"---"<<endl;
    combine(f1, f2, f3, n, m);
}

