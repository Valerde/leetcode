#include<bits/stdc++.h>
using namespace std;
int mod = 1000000007;
long long quitmul(int x,long long y) {
	int ret = 1;
	long long mul=x;
	while(y) {
		if(y%2==1) {
			ret=(long long)ret*mul%mod;
		}
		mul = mul*mul%mod;
		y/=2;

	}
	return ret;
}
int countGoodNumbers(long long n) {
	return (long long)(quitmul(5,((n+1)/2))*quitmul(4,(n/2)))%mod;
}
int main() {
	cout<<countGoodNumbers(50);
}



class Solution {
private:
    static constexpr int mod = 1000000007;
    
public:
    int countGoodNumbers(long long n) {
        // 快速幂求出 x^y % mod
        auto quickmul = [](int x, long long y) -> int {
            int ret = 1, mul = x;
            while (y > 0) {
                if (y % 2 == 1) {
                    ret = (long long)ret * mul % mod;
                }
                mul = (long long)mul * mul % mod;
                y /= 2;
            }
            return ret;
        };
        
        return (long long)quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % mod;
    }
};
