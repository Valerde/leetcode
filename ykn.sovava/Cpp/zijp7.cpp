#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    //¼òµ¥ÄæÍÆ
    int N = 0;
    while(cin >> N){
 
        vector<int> en_list;
        int copy_num = N;
        while(copy_num-- >0){           
            int en;
            cin >> en;
            en_list.push_back(en);
        }
 
        int start = 0;
 
        for(int i = en_list.size()-1;i>=0;i--){         
            int sum = en_list.at(i)+start;
            if(sum%2 == 0)start = sum/2;
            else start = (sum+1)/2;
 
        }
 
        cout << start << endl;
    }
 
    return 0;
}
