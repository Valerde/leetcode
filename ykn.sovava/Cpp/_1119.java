package Cpp;

import java.util.concurrent.*;
import java.util.function.IntConsumer;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月25日 19:38
 **/
public class _1119 {
    static int a = 0;
    public static void main(String[] args) {
        new FizzBuzz(3);
        ThreadPoolExecutor executor =
                new ThreadPoolExecutor(10, 10, 0,
                        TimeUnit.MINUTES, new LinkedBlockingQueue<>(1), Executors.defaultThreadFactory(), new ThreadPoolExecutor.AbortPolicy());

        CompletableFuture<Void> thread4 = CompletableFuture.runAsync(() -> {
            System.out.println(a);
            a += 1;
        }, executor);

        CompletableFuture<Void> thread3 = CompletableFuture.runAsync(() -> {
            System.out.println(a);
            a += 1;
        }, executor);
        CompletableFuture<Void> thread2 = CompletableFuture.runAsync(() -> {
            System.out.println(a);
            a += 1;
        }, executor);
        CompletableFuture<Void> thread1 = CompletableFuture.runAsync(() -> {
            System.out.println(a);
            a += 1;
        }, executor);

        try {
            CompletableFuture.allOf(thread1,thread2,thread3,thread4).get();
        } catch (InterruptedException e) {
            e.printStackTrace();
        } catch (ExecutionException e) {
            e.printStackTrace();
        }
        System.out.println("end");
    }
    static class FizzBuzz {
        private int n;

        Semaphore three = new Semaphore(0);

        Semaphore five = new Semaphore(0);
        Semaphore taf = new Semaphore(0);

        Semaphore other = new Semaphore(1);



        public FizzBuzz(int n) {
            this.n = n;

        }

        // printFizz.run() outputs "fizz".
        public void fizz(Runnable printFizz) throws InterruptedException {
            for (int i = 1; i <= n; i++) {
                if (i % 3 == 0 && i % 5 != 0) {
                    three.acquire();
                    printFizz.run();
                    other.release();
                }
            }
        }

        // printBuzz.run() outputs "buzz".
        public void buzz(Runnable printBuzz) throws InterruptedException {
            for (int i = 1; i <= n; i++) {
                if (i % 5 == 0 && i % 3 != 0) {
                    five.acquire();
                    printBuzz.run();
                    other.release();
                }
            }
        }

        // printFizzBuzz.run() outputs "fizzbuzz".
        public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
            for (int i = 1; i <= n; i++) {
                if (i % 3 == 0 && i % 5 == 0) {
                    taf.acquire();
                    printFizzBuzz.run();

                    other.release();
                }
            }

        }

        // printNumber.accept(x) outputs "x", where x is an integer.
        public void number(IntConsumer printNumber) throws InterruptedException {
            for (int i = 1; i <= n; i++) {
                other.acquire(1);
                if (i % 3 == 0 && i % 5 == 0) {
                    taf.release();
                } else if (i % 3 == 0 && i % 5 != 0) {
                    three.release();
                } else if (i % 5 == 0 && i % 3 != 0) {
                    five.release();
                } else {

                    printNumber.accept(i);
                    other.release();
                }
            }

        }
    }

}
