#include <bits/stdc++.h>
#include <climits>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(n,0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];

        }
    }

    vector<vector<int> > dp(n, vector<int>(1 << (n - 1), 0));
    dp[0][0] = 0;
    int k = 1 << (n - 1);
    for (int j = 0; j < k; j++) {
        for (int i = 0; i < n; i++) {
            if (j == 0) {
                dp[i][j] = v[i][j];
            } else {
                dp[i][j] = INT_MAX;
                for (int l = 1; l < n; l++) {
                    int index = 1 << (l - 1);
                    if ((index & j) > 0) {
                        int other = j ^ index;
                        dp[i][j] = min(v[i][l] + dp[l][other], dp[i][j]);
                    }
                }
            }
        }
    }
    cout << dp[0][k - 1] << endl;


}
// 64 Î»Êä³öÇëÓÃ printf("%lld")
