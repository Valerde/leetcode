#include<bits/stdc++.h>

using namespace std;
/*
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

你不需要保留每个分区中各节点的初始相对位置。


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
