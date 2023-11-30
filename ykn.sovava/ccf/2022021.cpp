#include<cstdio>
#include<algorithm>
#include<set>
#include<iostream>
using namespace std;
int main() {
	int n,k,count = 0,a,b;
	scanf("%d%d",&n,&k);
	set<int> s{0};

	for(int i = 0; i<k; i++) {
		scanf("%d%d",&a,&b);
		
		if(find(s.begin(),s.end(),b)==s.end()) {
			count++;
		}
		s.insert(a);
	}
	cout<<count<<endl;
}
