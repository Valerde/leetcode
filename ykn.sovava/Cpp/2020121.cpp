#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int tot=0,a,b;
	for(int i = 0;i<n;i++){
		scanf("%d%d",&a,&b);
		tot+=a*b;
	}
	
	cout<<max(0,tot)<<endl;
} 
