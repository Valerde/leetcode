/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int temp = 10000000;
        while(head!=nullptr){
        	if(head->val == temp){
        		return true;
        	}
        	head->val = temp;
        	head = head->next;
        }
        return false;
    }
};
