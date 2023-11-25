package com.sovava.pack;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月19日 18:53
 **/
public class TestClass {
 private static void testMethod(){
  System.out.println("testMethod");
 }
 public static void main(String[] args) {
  ((TestClass)null).testMethod();
 }
}
