#include<bits/stdc++.h>
using namespace std;
vector<int> xulp;
string str;
int flag=1;//1大写 到数字28   2小写 到数字28   3 数字到小写27
void handle(int i) {
	if(flag==1) {
		if(str[i]>='A'&&str[i]<='Z') {
			xulp.push_back(str[i]-'A');
		} else if(str[i]>='a'&&str[i]<='z') {
			xulp.push_back(27);
			xulp.push_back(str[i]-'a');
			flag=2;
		} else if(str[i]>='0'&&str[i]<='9') {
			xulp.push_back(28);
			xulp.push_back(str[i]-'0');
			flag=3;
		}
	} else if(flag==2) {
		if(str[i]>='A'&&str[i]<='Z') {
			xulp.push_back(28);
			xulp.push_back(28);
			xulp.push_back(str[i]-'A');
			flag=1;
		} else if(str[i]>='a'&&str[i]<='z') {

			xulp.push_back(str[i]-'a');
			flag=2;
		} else if(str[i]>='0'&&str[i]<='9') {
			xulp.push_back(28);
			xulp.push_back(str[i]-'0');
			flag=3;
		}
	} else if(flag==3) {
		if(str[i]>='A'&&str[i]<='Z') {
			xulp.push_back(28);

			xulp.push_back(str[i]-'A');
			flag=1;
		} else if(str[i]>='a'&&str[i]<='z') {
			xulp.push_back(27);
			xulp.push_back(str[i]-'a');
			flag=2;
		} else if(str[i]>='0'&&str[i]<='9') {

			xulp.push_back(str[i]-'0');
			flag=3;
		}
	}
}
int main() {
	int w,s;
	cin>>w>>s;

	cin>>str;


	for(int i = 0; i<str.length(); i++) {
		handle(i);
	}
	if(xulp.size()%2==1) {
		xulp.push_back(29);
	}

	vector<int> mazi;
	for(int i=0; i<xulp.size(); i+=2) {
		mazi.push_back(xulp.at(i)*30+xulp.at(i+1));
	}
	int mazilen = mazi.size();
	int len = w*((mazilen+1)/w+1);

	//校验长度
	int k ;
	if(s=-1) {
		k=0;
	} else {
		k= pow(2,s+1);
	}

	cout<<k<<endl;
	cout<<len-k<<endl;

	for(auto&& v: mazi) {
		cout<<v<<"\n";
	}
	for(int i=0; i<w-(mazilen+1)%w-k%w; i++) {
		cout<<900<<endl;
	}
}
