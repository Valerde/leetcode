#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n,a;
	int flag=0,first=0,last=0;
	double vs;
	scanf("%d",&n);
	if(n%2==0) {
		flag=1;
	} else {
		flag=0;
	}
	for(int i = 0; i<n; i++) {

		scanf("%d",&a);
		if(i==0) {
			first=a;
		}
		if(i==n-1) {
			last=a;
		}

		if(flag==0&&i==n/2) {

			vs=a;
		}
		if(flag==1&&(i==n/2-1||i==n/2)) {
			vs+=a*0.5;
		}


	}

	if(first<last) {
		swap(first,last);
	}

	if((int)(vs*2)%2==0) {
	printf("%d %d %d\n",first,vs,last);

	} else {
		printf("%d %.1lf %d\n",first,vs,last);
	}
	cout<<first<<" "<<vs<<" "<<last;

}
