package com.sovava.other.UCL_Prediction;

import java.security.SecureRandom;
import java.util.*;

/**
 * Description: 23-24赛季16进8抽签模拟
 *
 * @author: ykn
 * @date: 2023年12月15日 14:26
 **/
public class UCLPredictions {

    private static int teamSize = 16;

    private static double calcCnt = 10_00000L;

    private static String[] firLevel;
    private static String[] secLevel;
    private static final Map<Integer, Pair> playTeamMap = new HashMap<>();


    private static final Set<Integer> avoidTeamSet = new HashSet<>();

    public static void main(String[] args) {
        init();

        for (int i = 0; i < calcCnt; i++) {
            Set<Integer> oneTimeDraw = getOneTimeDraw();

            for (Integer key : oneTimeDraw) {
                playTeamMap.get(key).addCnt();
            }
        }

        for (Map.Entry<Integer, Pair> pairEntry : playTeamMap.entrySet()) {
            System.out.println(pairEntry.getValue().toString());
        }

    }

    public static void init() {
        teamSize = 16;
        calcCnt = 100000L;
        firLevel = new String[]{"拜仁", "阿森纳", "皇马", "皇社", "马竞", "多特", "曼城", "巴萨"};
        secLevel = new String[]{"哥本哈根", "埃因霍温", "那不勒斯", "国米", "拉齐奥", "巴黎", "莱比锡", "波尔图"};

        avoidTeamSet.add(getKey(0, 6));
        avoidTeamSet.add(getKey(5, 6));

        for (int i = 0; i < teamSize / 2; i++) {
            for (int j = 0; j < teamSize / 2; j++) {
                if (i != j && !avoidTeamSet.contains(getKey(i, j))) {
                    playTeamMap.put(getKey(i, j), new Pair(getKey(i, j)));
                }
            }
        }

    }


    private static Set<Integer> getOneTimeDraw() {

        Set<Integer> setRes = new HashSet<>();
        Set<Integer> setSec = new HashSet<>();
        Set<Integer> setFir = new HashSet<>();
        int drawTeamNum = 0;
        while (drawTeamNum < teamSize / 2) {
            boolean isRight = initNums(setRes, setFir, setSec);

            if (!isRight) {
                drawTeamNum = 0;
                setRes.clear();
            } else {
                drawTeamNum++;
            }

        }
        return setRes;
    }

    private static int getKey(int a, int b) {
        return a * 10 + b;
    }


    private static boolean initNums(Set<Integer> setRes, Set<Integer> setFir, Set<Integer> setSec) {
        Random random = new SecureRandom();

        Set<Integer> buji2 = new HashSet<>();
        Set<Integer> buji1 = new HashSet<>();

        for (int i = 0; i < teamSize / 2; i++) {
            buji2.add(i);
            buji1.add(i);
        }

        int secNum, firNum, key;
        int time = 0;
        do {
            time++;
            buji2.removeAll(setSec);
            buji1.removeAll(setFir);
            int secNumIdx = random.nextInt(buji2.size());
            int firNumIdx = random.nextInt(buji1.size());
            secNum = (int) buji2.toArray()[secNumIdx];
            firNum = (int) buji1.toArray()[firNumIdx];
            key = getKey(firNum, secNum);
            if (buji2.size() == 1 && time > 1) {
                setSec.clear();
                setFir.clear();
                return false;
            }

        } while (firNum == secNum || avoidTeamSet.contains(key));
        setSec.add(secNum);
        setFir.add(firNum);
        setRes.add(key);

        return true;
    }

    private static class Pair {
        private int key;
        private String pairName;
        private int cnt;
        private double total = calcCnt;

        public Pair(int key) {
            this.key = key;
            setPairName(key);
            this.cnt = 0;
            this.total = calcCnt;
        }

        public void setPairName(int key) {
            int b = key % 10;
            int a = key / 10;
            this.pairName = firLevel[a] + "-" + secLevel[b];
        }

        public void addCnt() {
            this.cnt++;
        }

        @Override
        public String toString() {
            return pairName + "：" + cnt + "次" + ";" + cnt / total;
        }
    }

}
