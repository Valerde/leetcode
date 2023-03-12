package java;

import org.testng.internal.collections.Pair;

import java.util.Arrays;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月12日 11:20
 **/
public class _1405 {
    public String longestDiverseString(int a, int b, int c) {

        StringBuffer sb = new StringBuffer();
        MPair[] pair = new MPair[]{new MPair(a, 'a'), new MPair(b, 'b'), new MPair(c, 'c')};


        int i = 0;
        while (true) {
            Arrays.sort(pair, (p1, p2) -> p2.fir - p1.fir);
            if (pair[1].fir == 0) break;

            if ((i >= 2) && (sb.charAt(i - 1) == sb.charAt(i - 2)) && (sb.charAt(i - 1) == pair[0].sec)) {
                sb.append(pair[1].sec);
                pair[1].fir--;

            } else {
                sb.append(pair[0].sec);
                pair[0].fir--;
            }
            i++;

        }
        if (i >= 2 && (sb.charAt(i - 1) != sb.charAt(i - 2)) && (sb.charAt(i - 1) == pair[0].sec) && pair[0].fir >= 0) {
            sb.append(pair[0].sec);
        } else if (i >= 2 && (sb.charAt(i - 1) == sb.charAt(i - 2)) && (sb.charAt(i - 1) != pair[0].sec) && pair[0].fir >= 0) {
            sb.append(pair[0].sec);
            if (pair[0].fir >= 2) sb.append(pair[0].sec);
        } else if ((i >= 2 && (sb.charAt(i - 1) != sb.charAt(i - 2)) && (sb.charAt(i - 1) != pair[0].sec) && pair[0].fir >= 0)) {
            sb.append(pair[0].sec);
            if (pair[0].fir >= 2) sb.append(pair[0].sec);
        }else if(i<2){
            sb.append(pair[0].sec);
            if (pair[0].fir >= 2) sb.append(pair[0].sec);
        }
        return sb.toString();

    }

    class MPair {
        public Integer fir;
        public Character sec;

        public MPair(Integer fir, Character sec) {
            this.fir = fir;
            this.sec = sec;
        }
    }

}
