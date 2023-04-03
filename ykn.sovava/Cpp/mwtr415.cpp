#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  map<int,int> m;
  for(int i = 2;i<=n;i++){
    int temp = 0;
    cin>>temp;
    m.emplace(i,temp);
  }
  vector<int> c(n+1);
  for(int i = 1;i<=n;i++){
    cin>>c[i];
  }
  vector<int> res(n+1,0);//-1表示当前为叶子结点
  vector<vector<int>> tree(n+1,vector<int>(0));
  for(auto it = m.rbegin();it!=m.rend();it++){
    // cout<<it->first<<" "<<it->second<<endl;
    int root = it->second,erzi = it->first;
    tree[root].push_back(erzi);
  }
  
  for(int i = n;i>0;i--){
    if(tree[i].size() == 0){
      res[i] = 1;
    }else{
      res[i] = c[i] ==1?res[tree[i][0]]+res[tree[i][1]]:res[tree[i][0]]^res[tree[i][1]];
    }
  }
  cout<<res[1];
  
}
