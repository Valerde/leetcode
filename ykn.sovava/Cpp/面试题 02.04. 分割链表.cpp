#include<bits/stdc++.h>

using namespace std;
/*
����һ�������ͷ�ڵ� head ��һ���ض�ֵ x �������������зָ���ʹ������ С�� x �Ľڵ㶼������ ���ڻ���� x �Ľڵ�֮ǰ��

�㲻��Ҫ����ÿ�������и��ڵ�ĳ�ʼ���λ�á�


*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* partition(ListNode* head, int x) {
    if(head == nullptr) return head;
	int _temp = 0;
	ListNode* p1 = head->next;
    ListNode* p2 = head;
	while(p1) {

		if(p1->val < x){
            p2->next = p1->next;p1->next = head;
            head=p1;
            p1 = p2->next;
        }else{
            p1 = p1->next;
            p2 = p2->next;
        }
	}
	return head;
}

int main() {

}
