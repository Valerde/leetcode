#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int res[N];

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i ++) {
		int t, c;
		cin >> t >> c;

		//�ڡ�l, r��ʱ����������ᣬ��tʱ�̿ɽ���
		int l = max(t - k - c + 1, 0);
		l = min(l, 200000);
		int r = max(0, t - k);
		r = min(r, 200000);

		//�ڡ�l, r��ʱ������ܳ��еļƻ�������һ
		res[l] += 1;
		res[r + 1] -= 1;
	}

	//���ò�ּ���ÿ��ʱ����ܳ��и���
	for (int i = 1; i < 200001; i ++) {
		res[i] += res[i - 1];
	}

	for (int i = 0; i < m; i ++) {
		int q;
		cin >> q;
		cout << res[q] << endl;
	}
	return 0;
}
