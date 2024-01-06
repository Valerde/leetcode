package com.sovava._24._01._2807在链表中插入最大公约数;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月06日 11:06
 **/
public class Solution {
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode fir = head.next;
        ListNode sec = head;
        while (fir != null) {
            int val = gcd(fir.val, sec.val);
            ListNode tmp = new ListNode(val);
            sec.next = tmp;
            tmp.next = fir;
            sec = fir;
            fir = fir.next;
        }

        return head;
    }



    private static int gcd(int a, int b) {
        int tmp = 0;
        while (a % b != 0) {
            tmp = b;
            b = a % b;
            a = tmp;
        }
        return b;
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
