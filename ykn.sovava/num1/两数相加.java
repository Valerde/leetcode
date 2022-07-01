package num1;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2022年06月26日 19:34
 **/

//
//public class ListNode {
//    int val;
//    ListNode next;
//
//    ListNode() {
//    }
//
//    ListNode(int val) {
//        this.val = val;
//    }
//
//    ListNode(int val, ListNode next) {
//        this.val = val;
//        this.next = next;
//    }
//}
//
//class Solution {
//    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
//        ListNode header = new ListNode(0);
//        ListNode l3 = header;
//        int carry = 0;
//        while (l1 != null || l2 != null) {
//            int x = l1 == null ? 0 : l1.val;
//            int y = l2 == null ? 0 : l2.val;
//            int sum = x + y + carry;
//            carry = sum / 10;
//            sum = sum % 10;
//            l3.next = new ListNode(sum);
//            l3 = l3.next;
//            if (l1 != null) {
//                l1 = l1.next;
//            }
//            if (l2 != null) {
//                l2 = l2.next;
//            }
//
//        }
//        if (carry==1){
//            l3.next = new ListNode(carry);
//        }
//        return header.next;
//    }
//
//}
