#include<bits/stdc++.h>
using namespace std;
double cal(double l,double r,char op){
  if(op == '+'){
    return l+r;
  }else if(op == '-'){
    return l-r;
  }else if(op == '*'){
    return l*r;
  }else if(op == '/'){
    return l/r;
  }
}
int main(){
  int n;
  cin>>n;
  vector<double> in(n);
  double res = 0;
  for(int i = 0;i<n;i++){
    cin>>in[i];
    res+=in[i];
  }
  int m;
  cin>>m;
  for(int i = 0;i<m;i++){
    int idx;
    char ch1,ch2;
    cin>>idx>>ch2;
    cout<<"cczo"<<idx<<" "<<ch2<<endl;
    double l = in[idx-1],r = in[idx];
    cout<<"uuju"<<l<<" "<<r<<endl;
    double ans = res-l-r+cal(l,r,ch2);
    printf("%.1f ",ans);
  }
}
