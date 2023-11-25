//package com.sovava.pack;
//
///**
// * Description: TODO
// *
// * @author: ykn
// * @date: 2023年03月29日 16:30
// **/
//public class Singleton {
//    private static volatile Singleton singleton;
//
//    public Singleton() {
//    }
//
//    public Singleton getSingleton() {
//        if (null == singleton) {
//            synchronized (this) {
//                if (null == singleton) {
//                    singleton = new Singleton();
//                }
//            }
//        }
//        return singleton;
//    }
//}
