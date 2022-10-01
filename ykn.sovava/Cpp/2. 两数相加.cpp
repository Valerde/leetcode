/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };


 ��������?�ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ���?����?�ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢?һλ?���֡�

���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����

����Լ���������� 0 ֮�⣬���������������� 0?��ͷ��

?


 */
#include<bits/stdc++.h>
using namespace std;
//��ʡ�ڴ淨 , ���ǱȽϷ���
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	int f = 0;
	int _temp  = 0;
	bool flag1 = false,flag2 = false;
	ListNode* head1 = l1;
	ListNode* head2 = l2;
	while(l1!=nullptr&&l2!=nullptr) {
		_temp = l1->val;
		l1->val = (l1->val+ l2->val +f)%10;
		f=(_temp+l2->val +f)/10;
		l1 = l1->next;
		l2 = l2->next;
		if(l1==nullptr) flag1 = true;
		if(l2==nullptr) flag2 = true;
	}

	if(flag1&&!flag2) {
		while(l2!=nullptr) {
			_temp = l2->val;
			l2->val = (l2->val + f)%10;
			f = (_temp + f)/10;
			l1->next = l2;
			l1 = l1->next;
			l2 = l2->next;
		}
		if(f!=0)
			l1->next = new ListNode(f);
	}
	if(!flag1&&flag2) {
		while(l1!=nullptr) {
			_temp = l1->val;
			l1->val = (l1->next+f)%10;
			f = (_temp + f)/10;
			l1 = l1->next;
		}
		if(f!=0) {
			l1->next = new ListNode(f);
		}
	}
	if(flag1&&flag2 {
	if(f!=0)l1->next = new ListNode(f);
	}
	return l1;
}


// �½�����
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *head = nullptr, *tail = nullptr;
	int carry = 0;
	while (l1 || l2) {
		int n1 = l1 ? l1->val: 0;
		int n2 = l2 ? l2->val: 0;
		int sum = n1 + n2 + carry;
		if (!head) {
			head = tail = new ListNode(sum % 10);
		} else {
			tail->next = new ListNode(sum % 10);
			tail = tail->next;
		}
		carry = sum / 10;
		if (l1) {
			l1 = l1->next;
		}
		if (l2) {
			l2 = l2->next;
		}
	}
	if (carry > 0) {
		tail->next = new ListNode(carry);
	}
	return head;
}

int main() {
}
