/*
* 4．一个正整数数组 arr, 数组满足 0 <= arr[i] <= 9。
*挑出任意个数，组成一个最大数，并且这个数能被 3 整除，并以字符串的形式返回
*/
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int main(void) {
	unsigned  long seed = time(0);
	srand(seed);
	int tempsum = 0;
	int flag = 0;
	unsigned long long num = long long(rand());
	int arr[20], len = 0;
	printf("%lld\n", num);
	vector<int>a,b;
	for (len = 0; num; len++) {
		arr[len] = num % 10;
		num /= 10;
		tempsum += arr[len];
		a.push_back(arr[len]);
		b.push_back(arr[len]);
	}
	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), cmp);
	if (tempsum % 3 == 0) {
		sort(arr, arr + len, cmp);
		for (int i = 0; i < len; i++) {
			printf("%d", arr[i]);
		}
		return 0;
	}
	for (int i = 0; i < len; i++) {
		if ((tempsum - arr[i]) % 3 == 0) {
			flag = 0;
			a.erase(a.begin() + i);
			sort(a.begin(), a.end(),cmp);
			for (int k = 0; k <a.size(); k++) {
				printf("%d", a[k]);
			}printf("\n");
			a.insert(a.begin() + i, arr[i]);
		}
	}
	for (int i = 0; i < len-1; i++) {
		for (int j = i + 1; j < len; j++) {
			if ((tempsum - arr[i] - arr[j]) % 3 == 0) {
				b.erase(b.begin() + j);
				b.erase(b.begin() + i);
				sort(b.begin(), b.end(),cmp);
				for (int k = 0; k < b.size(); k++) {
					printf("%d", b[k]);
				}
				printf("\n");
				b.insert(b.begin() + i, arr[i]);
				b.insert(b.begin() + j, arr[j]);
			}
		}
	}
	return 0;
}