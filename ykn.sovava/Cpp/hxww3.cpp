#include<bits/stdc++.h>
using namespace std;

bool isprime(int num) { //�ж�һ�����Ƿ�������
	for(int i = 2; i * i <= num; i++) { //����������num
		if(num % i == 0) //�����������
			return false;
	}
	return true;
}

bool find(int num, vector<int>& evens, vector<bool>& used, vector<int>& match) {
	for(int i = 0; i < evens.size(); i++) { //����ÿ��ż���������Ƚ�
		if(isprime(num + evens[i]) && !used[i]) {
			used[i] = true;
			if(match[i] == 0 || find(match[i], evens, used, match)) { //�����i��ż����δ��ԣ����߸�����Ե��������б��ѡ��
				match[i] = num; //����Ը���
				return true;
			}
		}
	}
	return false;
}
int main() {
	int n;
	while(cin >> n) {
		vector<int> odds;
		vector<int> evens;
		vector<int> nums(n);
		for(int i = 0; i < n; i++) { //����n����
			cin >> nums[i];
			if(nums[i] % 2) //����
				odds.push_back(nums[i]);
			else //ż��
				evens.push_back(nums[i]);
		}
		int count = 0;
		if(odds.size() == 0 || evens.size() == 0) { //ȱ����������ż���޷���������
			cout << count << endl;
			continue;
		}
		vector<int> match(evens.size(), 0); //ͳ��ÿ��ż����������ĸ�����
		for(int i = 0; i < odds.size(); i++) { //����ÿ������
			vector<bool> used(evens.size(), false); //ÿһ��ż����û�ù�
			if(find(odds[i], evens, used, match)) //�ܷ��ҵ���Ե�ż������Ҫ����
				count++;
		}
		cout << count << endl;
	}
	return 0;
}
