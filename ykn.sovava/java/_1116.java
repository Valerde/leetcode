package com.sovava.pack;

import java.util.concurrent.Semaphore;
import java.util.function.IntConsumer;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月25日 17:00
 **/
public class _1116 {
    class ZeroEvenOdd {
        private int n;
        Semaphore zero = new Semaphore(1);
        Semaphore even = new Semaphore(0);
        Semaphore odd = new Semaphore(0);
        int num = 1;

        public ZeroEvenOdd(int n) {
            this.n = n;
        }

        // printNumber.accept(x) outputs "x", where x is an integer.
        public void zero(IntConsumer printNumber) throws InterruptedException {
            while (num < n) {
                zero.acquire();
                printNumber.accept(0);
                if (num % 2 == 1) {
                    odd.release();
                } else {
                    even.release();
                }
//                Thread.yield();
            }


        }

        public void even(IntConsumer printNumber) throws InterruptedException {
            while (num < n) {
                even.acquire();
                printNumber.accept(num);
                num++;
                zero.release();
//                Thread.yield();
            }

        }

        public void odd(IntConsumer printNumber) throws InterruptedException {
            while (num < n) {
                odd.acquire();
                printNumber.accept(num);
                num++;
                zero.release();
//                Thread.yield();
            }
        }
    }
}
