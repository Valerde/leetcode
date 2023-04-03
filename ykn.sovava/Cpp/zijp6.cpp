#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> bi{1024, 64, 16, 4, 1};
    int N;
    cin >> N;
    N = 1024 - N;
    int res = 0, j = 0;
    while (N) {
        res += N / bi[j];
        N = N % bi[j];
        j++;
    }
    cout << res;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")
