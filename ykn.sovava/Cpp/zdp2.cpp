#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> dragons(N);

    // ����ÿ��ɽ���еĶ��������͸�������������ֵ
    for (int i = 0; i < N; i++) {
        int ki;
        cin >> ki;
        dragons[i].resize(ki);
        for (int j = 0; j < ki; j++) {
            cin >> dragons[i][j];
        }
    }

    // �������������Ҫ�߱�������ֵ
    int required_courage = 0;
    int current_courage = 0;

    for (int i = 0; i < N; i++) {
        sort(dragons[i].begin(), dragons[i].end());

        for (int j = 0; j < dragons[i].size(); j++) {
            if (current_courage >= dragons[i][j]) {
                current_courage++;
            } else {
                required_courage += (dragons[i][j] - current_courage + 1);
                current_courage = dragons[i][j] + 1;
            }
        }
    }

    cout << required_courage << endl;

    return 0;
}

