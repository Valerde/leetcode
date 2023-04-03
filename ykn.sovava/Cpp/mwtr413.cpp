#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(n,0);
  vector<int> op(m);
  vector<int> x(m);
  vector<int> y(m);
  vector<int> qm(n,0);
  for(int i = 0;i<m;i++){
    cin>>op[i];
  }  
  for(int i = 0;i<m;i++){
    cin>>x[i];
  }  
  for(int i = 0;i<m;i++){
    cin>>y[i];
  }
  
  for(int i = 0;i<m;i++){
    if(op[i]==1){
      cout<<qm[y[i]-1]-qm[x[i]-1]+a[x[i]-1]<<" ";
    }else if(op[i] == 0){
      int idx = x[i]-1,temp = a[idx];
      for(int j = idx;j<n;j++){
        qm[j] = qm[j]-temp+y[i];
        a[idx] = y[i];
      }
    }
//    cout<<"ai";
//    for(int k = 0;k<n;k++){
//    	cout<<qm[k]<<" ";
//    }
//    cout<<endl;
  }
}
