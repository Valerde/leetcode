#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n, m;
int res = 0;
int mod = 10000;
vector<vector<int>> step{
    {1, 0},
    {0, 1}
};
void dfs(int x, int y, vector<vector<int>>& mp, int energy) {
    if (x == n || y == m)return;
    if (x == n - 1 && y == m - 1) {
        res = (res + 1) % mod;
        return;
    }
    // energy--;
    if (energy == 0)energy = mp[x][y];
    dfs(x + step[0][0], y + step[0][1], mp, energy - 1);
    dfs(x + step[1][0], y + step[1][1], mp, energy - 1);
}

int main() {
    int t;
    while (t--) {
        res = 0;
        cin >> n >> m;
        vector<vector<int>> mp(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mp[i][j];
            }
        }

        dfs(0,0,mp,mp[0][0]);
        cout<<res<<endl;

    }
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")
