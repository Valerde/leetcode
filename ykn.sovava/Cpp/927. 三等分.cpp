#include<bits/stdc++.h>
/*
����һ���� 0 �� 1 ��ɵ�����?arr?��������ֳ� ?3?���ǿյĲ��� ��ʹ��������Щ���ֱ�ʾ��ͬ�Ķ�����ֵ��

��������������뷵���κ�?[i, j]������ i+1 < j������һ����

arr[0], arr[1], ..., arr[i]?Ϊ��һ���֣�
arr[i + 1], arr[i + 2], ..., arr[j - 1]?Ϊ�ڶ����֣�
arr[j], arr[j + 1], ..., arr[arr.length - 1]?Ϊ�������֡�
��������������ʾ�Ķ�����ֵ��ȡ�
����޷��������ͷ���?[-1, -1]��

ע�⣬�ڿ���ÿ����������ʾ�Ķ�����ʱ��Ӧ�����俴��һ�����塣���磬[1,1,0]?��ʾʮ�����е�?6����������?3�����⣬ǰ����Ҳ�Ǳ�����ģ�����?[0,1,1] ��?[1,1]?��ʾ��ͬ��ֵ��
*/
using namespace std;
vector<int> threeEqualParts(vector<int>& arr) {

	int num = 0;
	for(auto&& a:arr) {
		num+=a;
	}
	if(num%3!=0) return {-1,-1};
	else if (num==0) return {0,2};

	int n = arr.size();
	int partial = num/3;
	int fir = 0, sec = 0 , thi = 0;
	for(int i = 0,cnt = 0; i<n; i++) {
		if(arr[i]) {
			if(cnt==(partial)) sec=i;
			else if(cnt==(2*partial)) thi = i;
			else if(cnt == 0) fir = i;
			cnt++;
		}
	}

	int len = n - thi;
	for(int i = 0; i<len; i++)
		if(arr[fir+i]!=arr[sec+i]||arr[sec+i]!=arr[thi+i]) {
			return {-1,-1};
		}
	return {fir+len-1,sec+len};

}




int main() {

	vector<int> arr {0,1,0,1,1,0,1,1,0,1};

	vector<int> res = threeEqualParts(arr);
	cout<<res[0]<<" "<<res[1];
}

/*
�������һ�ַַ�ʹ�������ǿղ�������ʾ�Ķ�����ֵ��ͬ����ô����ÿһ���� 11 ������һ������ȵġ�
�������˼�룬��������ͳ������ \textit{arr}arr �� 11 �ĸ�����������Ϊ \textit{sum}sum��
��� \textit{sum}sum ���ܱ� 33 ��������ô��Ȼ��������ȷ�ַ���
����ÿһ�����ֶ�Ӧ���� \textit{partial} = \dfrac{\textit{sum}}{3}partial=3sum?  �� 11��

���ǳ����ҵ� \textit{arr}arr �е� 11 �� 11 ���ֵ�λ�� \textit{first}first���� \textit{partial} + 1partial+1 �� 11 ���ֵ�λ�� \textit{second}second �Լ��� 2 \times \textit{partial} + 12��partial+1 �� 11 ���ֵ�λ�� \textit{third}third����Ϊÿһ����ĩβ�� 00 �����ƶ�����һ���ֵ��ײ��Ӷ��ı������ֵ�Ĵ�С, ����ÿһ���ֵ�ĩβ���Խ綨������ע�⵽�������ĩβ���޷��ı�ģ�������� [\textit{third}, \textit{arr.length} - 1][third,arr.length?1] ����ʾ�Ķ�����ֵ���Թ̶���

�� \textit{len} = \textit{arr.length} - \textit{third}len=arr.length?third����ʾ������ֵ�ĳ��ȡ�������ֻ��Ҫ�ж� [\textit{first}, \textit{first} + \textit{len})[first,first+len)��[\textit{second}, \textit{second} + \textit{len})[second,second+len) �� [\textit{third}, \textit{third} + \textit{len})[third,third+len) �Ƿ���ȫ��ͬ���ɡ�ǰ���� \textit{first} + \textit{len} \le \textit{second}first+len��second ���� \textit{second} + \textit{len} \le \textit{third}second+len��third��

�������������������ȫ��ͬ�ģ���ô�𰸾��� [\textit{first} + \textit{len} - 1, \textit{second} + \textit{len}][first+len?1,second+len]�������Ҫע�⵽����� \textit{sum} = 0sum=0��������Ҫֱ�ӷ��ش� [0, 2][0,2]��������������Ϸ��𰸣���

*/
