#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<ll> > in(n,vector<ll>(2,0));
    for(int t =0;t<n;t++){
        cin>>in[t][0]>>in[t][1];
    }

    sort(in.begin(),in.end(),[&](const vector<ll> a,const vector<ll> b){
        if(a[0]==b[0])return a[1]<b[1];
        return a[0]<b[0];
    });

    ll ma=0;
    int s = 0;
    for(int i = n-1;i>=s;i--){
        for(int j=i-1;j>=s;j--){
            
            if(in[i][1]+in[j][1]>=in[i][0]+in[j][0]){
                s=i;
                ma=max(ma,in[i][0]+in[j][0]);
                break;
            }
            ma=max(ma,in[i][1]+in[j][1]);
        }
    }
    // printf("%.1f",ma/2.0);
    cout<<ma/2.0;

    return 0;
}
