#include<bits/stdc++.h>
using namespace std;
map<int,int> ma,mb;
int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	int ind,val;
	for(int i = 0;i<a;i++){
		scanf("%d%d" ,&ind,&val);
		ma[ind]=val;
	}
	for(int i = 0;i<b;i++){
		scanf("%d%d",&ind,&val);
		mb[ind]=val;
	}
	long long to=0;
	for(auto&& it = ma.begin();it!=ma.end();it++){
		if(mb[it->first]!=0){
			to+=mb[it->first]*it->second;
		}
	}
	cout<<to<<endl;
} 
/*
10 3 4
4 5
7 -3
10 1
1 10
4 20
5 30
7 40
*/
