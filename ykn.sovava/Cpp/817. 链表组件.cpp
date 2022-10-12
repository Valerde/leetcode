#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


int numComponents(ListNode* head, vector<int>& nums) {
	if(head->next ==nullptr) return head->val==nums[0]?1:0;

	set<int> s(nums.begin(),nums.end());

	ListNode* fir = head;
	ListNode* sec = head;
	int cnt = 0;
	while(fir!=nullptr) {
		if(fir==head) {
			if(s.find(fir->val)!=s.end())  cnt++;
			fir = fir->next;
		} else {
			if(s.find(fir->val)!=s.end()&&s.find((sec->val))==s.end()) cnt++;
			sec = sec->next;
			fir = fir->next;
		}

	}
	return  cnt;
}
int main() {}
