#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> x(n),y(n),z(n);
  for(int i = 0;i<n;i++)    cin>> x[i];  
  for(int i = 0;i<n;i++)    cin>> y[i];  
  for(int i = 0;i<n;i++)    cin>> z[i];
  int m;
  cin>>m;
  vector<int> q(m);
  for(int i = 0;i<m;i++)    cin>> q[i];
  //≤Ó÷µ
  vector<int> ia(n);
  for(int i = 0;i<n;i++){
    ia[i] = x[i] - y[i];
  }
  vector<int> qm(n);
  qm[0] = ia[0];
  for(int i = 1;i<n;i++){
    qm[i] = qm[i-1]+ia[i];
  }
  
  for(int i = 0;i<m;i++){
    int mi = INT_MAX;
    int idx = q[i]-1;
    for(int j = idx;j>=0;j--){
      mi = min(mi,z[j]*(qm[idx]-qm[j]+ia[j]));
    }
    cout<<mi<<" ";
  }
  
}
