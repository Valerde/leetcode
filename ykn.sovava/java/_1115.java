package com.sovava.pack;

import java.util.concurrent.Semaphore;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月25日 15:50
 **/
public class _1115 {
    class FooBar {
        private int n;
        private AtomicInteger first = new AtomicInteger(0);
        private AtomicInteger second = new AtomicInteger(0);

        public FooBar(int n) {
            this.n = n;
        }

        public void foo(Runnable printFoo) throws InterruptedException {

            for (int i = 0; i < n; i++) {
                while (second.get() - first.get() == -1 && first.get() != i) ;
                // printFoo.run() outputs "foo". Do not change or remove this line.
                printFoo.run();
                first.incrementAndGet();
            }
        }

        public void bar(Runnable printBar) throws InterruptedException {

            for (int i = 0; i < n; i++) {
                while (second.get() - first.get() != -1 && second.get() != i) ;
                // printBar.run() outputs "bar". Do not change or remove this line.
                printBar.run();
                second.incrementAndGet();
            }
        }
    }//上述方法会while死循环

    class FooBar1 {
        private int n;
        private Lock lock = new ReentrantLock();
        boolean flag = true;

        public FooBar1(int n) {
            this.n = n;
        }

        public void foo(Runnable printFoo) throws InterruptedException {

            for (int i = 0; i < n; ) {
                lock.lock();
                try {
                    if (flag) {
                        // printFoo.run() outputs "foo". Do not change or remove this line.
                        printFoo.run();
                        flag = !flag;
                        i++;
                    }
                } finally {
                    lock.unlock();
                }

            }
        }

        public void bar(Runnable printBar) throws InterruptedException {

            for (int i = 0; i < n; ) {
                lock.lock();
                try {
                    if (!flag) {
                        // printBar.run() outputs "bar". Do not change or remove this line.
                        printBar.run();
                        i++;
                        flag = !flag;
                    }
                } finally {
                    lock.unlock();
                }

            }
        }
    }

    class FooBar2 {
        private int n;
        Semaphore fooSema = new Semaphore(1);
        Semaphore barSema = new Semaphore(0);
        public FooBar2(int n) {
            this.n = n;
        }

        public void foo(Runnable printFoo) throws InterruptedException {

            for (int i = 0; i < n; i++) {
                fooSema.acquire();
                // printFoo.run() outputs "foo". Do not change or remove this line.
                printFoo.run();
                barSema.release();
            }
        }

        public void bar(Runnable printBar) throws InterruptedException {

            for (int i = 0; i < n; i++) {
                // printBar.run() outputs "bar". Do not change or remove this line.
                barSema.acquire();
                printBar.run();
                fooSema.release();
            }
        }
    }
}
