#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        int len = str.size();
        string res = "";
        if (len <= 2)cout << str;
        else {
            res += str[0];
            res += str[1];
            int j = 2;
            for (int i = 2; i < len; i++) {
                if (str[i] == res[j - 1] && str[i] == res[j - 2]) {
                    // str[i] = '1';
                    continue;
                } else if (j >= 3 && str[i] == res[j - 1] && res[j - 2] == res[j - 3]) {
                    // str[i] = '1';
                    continue;
                }
                res += str[i];
                j++;
            }
        }

        cout << res << endl;
    }
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")
