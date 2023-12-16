package com.sovava.other.huaweiInterview;


import java.util.*;

public class huawei2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int start = sc.nextInt();
        int end = sc.nextInt();

        int cnt = 0;
        for(int i  = start;i<=end;i++){
            if((!String.valueOf(i).contains("4"))&& (!String.valueOf(i).contains("18"))){
                cnt++;
            }
        }
        System.out.println(cnt);

    }
}
