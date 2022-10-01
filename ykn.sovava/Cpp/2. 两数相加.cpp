/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };


 给你两个?非空 的链表，表示两个非负的整数。它们每位数字都是按照?逆序?的方式存储的，并且每个节点只能存储?一位?数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0?开头。

?


 */
#include<bits/stdc++.h>
using namespace std;
//最省内存法 , 但是比较繁琐
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


// 新建链表
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
