/*
����һ�����飬������ 1 �� N ���е�������������ȱ���������֡������� O(N) ʱ����ֻ�� O(1) �Ŀռ��ҵ�������

������˳�򷵻����������־��ɡ�
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> missingTwo(vector<int>& nums) {

	int xornum = 0 ;
	for(int i = 1; i<=nums.size()+2; i++)		xornum^=i;
	for(auto a:nums) xornum^=a;
	//��ʱ x1^x2==xornum

	int lsb = xornum&(-xornum);//lsb Ϊxornum��͵�1

	//��ôlsb��1~N��������� , ����0���0���ֽ��
	//��1��һ����,�ض�ֻ���ҵ�һ��(��Ϊxornum&-xornum^x1 == x1^x2&-(x1^x2)^x1 == x2&-(x1^x2)  )
	int type = 0;
	for(int i = 1; i<=nums.size()+2; i++)
		if(lsb&i)	type^=i;

	for(auto a:nums) {
		if(lsb&a) type^=a;
	}
	vector<int> v {type,type^xornum};
	return v;
}

int main() {
	vector<int> nums {2,3};
	vector<int> res = missingTwo(nums);

//	cout<<res[1]<<" " <<res[0];

	int x1 = 3,x2 = 4;//x1 = 11 , x2 100
	int r = x2&(-(x1^x2));
	cout<<r;
}
