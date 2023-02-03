#include<bits/stdc++.h>
using namespace std;
//仅能用来读取数字 
template <typename Tp>
void read(Tp &x) {
	x = 0;
	int fh = 1;
	char ch = 1;
	while(ch != '-' && (ch < '0' || ch > '9'))ch = getchar();
	if(ch == '-') fh = -1, ch = getchar();
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= fh;
}

int main() {
	int a , b;
	vector<int> v(10,1);
	char c;
	//string str;
	read(a);
	cout<<"a = "<<a<<endl;
	read(v[5]);
	for(int i = 0; i<10; i++) {
		cout<<v[i]<<" ";
	}
	cout<<endl;
	read(c);
	//cin>>c;
	cout<<"char = "<<c<<endl;
	//read(str);
	//cout<<"str = "<<str<<endl;
	return 0;
}
