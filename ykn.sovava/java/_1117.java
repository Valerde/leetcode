package com.sovava.pack;

import java.util.concurrent.Semaphore;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月25日 17:25
 **/
public class _1117 {
    class H2O {
        Semaphore h = new Semaphore(1);
        Semaphore o = new Semaphore(0);
        int on = 0;
        public H2O() {

        }

        public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
//            h.acquire(2);
            // releaseHydrogen.run() outputs "H". Do not change or remove this line.
            h.acquire(1);
            releaseHydrogen.run();
            on++;
            if(on==2){
                on=0;
                o.release();
            }else{
                h.release();
            }
        }

        public void oxygen(Runnable releaseOxygen) throws InterruptedException {

            // releaseOxygen.run() outputs "O". Do not change or remove this line.
            o.acquire();
            releaseOxygen.run();
            h.release();
        }
    }
}
