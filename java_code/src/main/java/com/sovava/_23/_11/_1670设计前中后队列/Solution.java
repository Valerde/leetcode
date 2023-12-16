package com.sovava._23._11._1670设计前中后队列;

import javax.swing.*;
import java.util.ArrayDeque;
import java.util.Deque;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年11月28日 9:27 AM
 **/
public class Solution {
    class FrontMiddleBackQueue {

        private final Deque<Integer> left;
        private final Deque<Integer> right;


        public FrontMiddleBackQueue() {
            left = new ArrayDeque<>();
            right = new ArrayDeque<>();
        }

        public void pushFront(int val) {
            left.offerFirst(val);
            reshape();
        }

        public void pushMiddle(int val) {
            if (left.size() < right.size()) {
                left.offerLast(val);
            } else {
                right.offerFirst(val);
            }
        }

        public void pushBack(int val) {
            right.offerLast(val);
            reshape();
        }

        public int popFront() {
            Integer integer = left.pollFirst();
            if (null == integer) {
                integer = right.pollFirst();
            }

            reshape();
            return null == integer ? -1 : integer;
        }

        public int popMiddle() {
            Integer integer;
            if (left.size() == right.size()) {
                integer = left.pollLast();
            } else {
                integer = right.pollFirst();
            }
            return null == integer ? -1 : integer;
        }

        public int popBack() {
            Integer integer = right.pollLast();
            if (integer == null) {
                integer = left.pollLast();
            }
            reshape();
            return null == integer ? -1 : integer;
        }

        private void reshape() {
            if (left.size() - right.size() == 1) {
                right.offerFirst(left.pollLast());
            } else if (right.size() - left.size() == 2) {
                left.offerLast(right.pollFirst());
            }
        }
    }

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue obj = new FrontMiddleBackQueue();
 * obj.pushFront(val);
 * obj.pushMiddle(val);
 * obj.pushBack(val);
 * int param_4 = obj.popFront();
 * int param_5 = obj.popMiddle();
 * int param_6 = obj.popBack();
 */
}
