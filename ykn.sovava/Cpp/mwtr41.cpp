#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  while(cin>>n>>m){
    double res = 0;
    for(int i = 0;i<m;i++){
      res+=n;
      n = sqrt(n);    
    }
    printf("%.2f\n",res);
  }
}
