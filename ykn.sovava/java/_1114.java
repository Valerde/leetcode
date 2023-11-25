package com.sovava.pack;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.Semaphore;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月25日 15:30
 **/
public class _1114 {
    class Foo {
        //        CountDownLatch
        private AtomicInteger firstJobDone = new AtomicInteger(0);
        private AtomicInteger secondJobDone = new AtomicInteger(0);
        private AtomicInteger thirdJobDone = new AtomicInteger(1);

        public Foo() {

        }

        public void first(Runnable printFirst) throws InterruptedException {
            while (thirdJobDone.get() != 1) {
            }
            // printFirst.run() outputs "first". Do not change or remove this line.
            printFirst.run();
            firstJobDone.incrementAndGet();
        }

        public void second(Runnable printSecond) throws InterruptedException {
            while (firstJobDone.get() != 1) {
            }
            // printSecond.run() outputs "second". Do not change or remove this line.
            printSecond.run();
            secondJobDone.incrementAndGet();
        }

        public void third(Runnable printThird) throws InterruptedException {
            while (secondJobDone.get() != 1) {
            }
            // printThird.run() outputs "third". Do not change or remove this line.
            printThird.run();
            secondJobDone.decrementAndGet();
        }
    }

    class Foo1 {
        private CountDownLatch second = new CountDownLatch(1);
        private CountDownLatch third = new CountDownLatch(1);
        private CountDownLatch first = new CountDownLatch(0);

        public Foo1() {

        }

        public void first(Runnable printFirst) throws InterruptedException {
            first.await();
            printFirst.run();
            second.countDown();
        }

        public void second(Runnable printSecond) throws InterruptedException {
            second.await();
            printSecond.run();
            third.countDown();
        }

        public void third(Runnable printThird) throws InterruptedException {
            third.await();
            printThird.run();
            first.countDown();
        }
    }

    class Foo2 {

        Semaphore firSema = new Semaphore(1);
        Semaphore thrSema = new Semaphore(0);
        Semaphore secSema = new Semaphore(0);

        public Foo2() {

        }

        public void first(Runnable printFirst) throws InterruptedException {
            firSema.acquire();
            printFirst.run();
            secSema.release();
        }

        public void second(Runnable printSecond) throws InterruptedException {
            secSema.acquire();
            printSecond.run();
            thrSema.release();
        }

        public void third(Runnable printThird) throws InterruptedException {
            thrSema.acquire();
            printThird.run();
            firSema.release();
        }
    }
}
