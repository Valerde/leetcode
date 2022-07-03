package _9回文数;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2022年07月03日 12:49
 **/
public class Solution {
    public static boolean isPalindrome(int x) {
        int temp = x;
        if (x < 0) return false;
        int result = 0;
        while (x > 0) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        if (temp == result){
            return true;
        }else{
            return false;
        }
    }

    public static void main(String[] args) {
        System.out.println(isPalindrome(121));
    }
}
