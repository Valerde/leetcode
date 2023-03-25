#include <iostream>
using namespace std;
#include<bits/stdc++.h>
typedef long long ll;
ll mod = 998244353;
ll jpig(int n, int m) {
    ll res = 1;
    for (int i = 1; i <= n; i++) {
        res = res * i % mod;
    } cout << res << endl;
    for (int i = 1; i <= m; i++) {
        res = res / i % mod;
    } cout << res << endl;
    for (int i = 1; i <= n - m; i++) {
        res = res / i % mod;
    } cout << res << endl;
    return res;
}
int main() {

    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    n = n * n;
    ll res = 1;
     cout << res << endl;
    res =res* jpig(n, a)%mod;
     cout << res << endl;
    n = n - a;
    res =res* jpig(n, b)%mod;
     cout << res << endl;
    n = n - b;
    res =res* jpig(n, c)%mod;

    cout << res << endl;

    // int a, b;
    // while (cin >> a >> b) { // 注意 while 处理多个 case
    //     cout << a + b << endl;
    // }
}
// 64 位输出请用 printf("%lld")
