#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
bool isPrime(int i) {
	if(i==1)return false;

	for(int j = 2; j*j<=i; j++) {
		if(i%j==0)
			return false;
	}
	return true;
}

int numPrimeArrangements(int n) {
	int prinum = 0;
	for(int i = 1;i<=n;i++)
	if(isPrime(i))prinum++;
	long ans = 1;
	for(int i = 1;i<=prinum;i++)		ans=(ans*i)%MOD;
	
	for(int i = 1;i<=(n-prinum);i++) ans = (ans*i)%MOD;
	
	return ans;
}

int main(){
	
	cout<<numPrimeArrangements(100);
}
