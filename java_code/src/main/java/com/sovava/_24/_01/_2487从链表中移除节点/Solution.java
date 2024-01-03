package com.sovava._24._01._2487从链表中移除节点;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月03日 19:23
 **/
public class Solution {
    public ListNode removeNodes(ListNode head) {
        head = reverse(head);

        for (ListNode p = head; p.next != null; ) {
            if (p.val > p.next.val) {
                p.next = p.next.next;
            } else {
                p = p.next;
            }
        }

        return reverse(head);
    }

    public ListNode reverse(ListNode head) {
        ListNode node = new ListNode();
        while (head != null) {
            ListNode p = head;
            head = head.next;
            p.next = node.next;
            node.next = p;
        }
        return node.next;
    }

    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }
}
