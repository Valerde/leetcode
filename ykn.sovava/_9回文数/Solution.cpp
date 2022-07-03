class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        if (x < 0) return false;
        long result = 0;
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
};
/*
4 ms	5.8 MB	C++
4 ms	40.5 MB	Java
这种简单乘除运算下,运行时间并不有所提高
内存消耗会大大减少
 */