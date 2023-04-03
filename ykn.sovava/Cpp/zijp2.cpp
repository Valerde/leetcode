#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> ns(N);
    for (int i = 0; i < N; i++) {
        cin >> ns[i];
    }
    int fir = 2;
    int lst = 0;
    int res = 0;
    for( fir = 2,lst=0;lst<N-2;lst++){
    	long p;
    	while(fir<N&& (ns[fir]- ns[lst]<=D)){
    		fir++;
    	}
    	p = fir - lst - 1;
    	res = res+(p*(p-1)/2)%99997867;
    }
    
    cout << res;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")
