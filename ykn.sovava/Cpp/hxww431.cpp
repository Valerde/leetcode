#include<bits/stdc++.h>
using namespace std;
int main() {
	string str;
	cin>>str;
	int cnt = 0,len = str.size();
	for(int i = 0; i<len; i++) {
		if(str[i] == '1') cnt++;
	}
	if(cnt%3!=0||cnt==0) {
		cout<<-1;
		return 0;
	}
	int prtNum = cnt/3;
	int idx1=0,idx2 = len-1,idx3;
	int fir=0,sec = 0;
	string str1 = "",str2 = "",str3 = "";
	for(int i = 0; i<prtNum;) {
//		cout<<str[idx2]-'0'<<" "<<(len-idx2-1)<<" "<<((str[idx2]-'0')<<(len-idx2-1))<<endl;
		sec = sec+((str[idx2]-'0')<<(len-idx2-1));

//		cout<<sec<<endl;
		if(str[idx2]-'0'==1)i++;
		idx2--;
	}
	idx2++;
//	for(int i =idx2;
	for(int i = 0; i<prtNum;) {
		fir = (fir<<1)+str[idx1]-'0';


		if(str[idx1]-'0'==1)i++;
		idx1++;
	}
//	cout<<fir<<" "<<sec;
	if(fir!=sec) {
		cout<<-1;
		return 0;
	}
	for(int i = 0; i<idx1; i++) str1+=str[i];
	int mid = 0;
	idx3=idx1;
	for(int i = 0; i<prtNum;) {
		mid = (mid<<1)+str[idx3]-'0';


		if(str[idx3]-'0'==1)i++;
		idx3++;
	}
//	cout<<str1;
	int temp = 0;
	if(idx3<=idx2&&fir%mid==0&&(fir/mid%2==1||fir/mid%2 ==0)) {
		temp = fir/mid-1;
	} else {
		cout<<-1;
		return 0;
	}
	for(int i = idx1; i<idx3+temp; i++) {
		str2+=str[i];
	}
	for(int i = idx3+temp; i<len; i++) {
		str3+=str[i];
	}
	cout<<str1<<" "<<str2<<" "<<str3<<endl;



}
