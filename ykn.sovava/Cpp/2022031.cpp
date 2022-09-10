#include<bits/stdc++.h>
#include <iostream>
using namespace std;
const int N = 100010;

int n, k, res;
int l[N], r[N], m[N];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i ++ ) {
    	scanf("%d%d", &l[i], &r[i]);
    	m[l[i-1]]=1;
    	if(m[r[i]]!=1){
    		res++;
		}
	}
    
    cout << res << endl;
    return 0;
}
