#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,m;
	scanf("%d%d",&n,&m);

	long ot=0,nt=0,ind=1,indt=-1,total=0,an,sn;

	for(int i=0; i<n; i++) {
		//ot=nt;
		nt = 0;
		scanf("%d",&an);
		total+=an;
		int j=0;
		for(; j<m; j++) {
			scanf("%d",&sn);
			nt+=sn;
		}
		total+=nt;
		if(ot>nt){
			ind=i;
			indt=-nt;
			ot=nt;
		}
	}

	cout<<total<<" "<<ind+1<<" "<<indt<<endl;
}

/*
3 3
73 -8 -6 -4
76 -5 -10 -8
80 -6 -15 0
*/
