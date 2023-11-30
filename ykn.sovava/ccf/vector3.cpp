#include<vector>
#include<iostream>
using namespace std;
int main(){
	vector<string> vec{"ykn","wyp"};
	auto it = vec.cbegin();
//	for(;it<vec.cend();it++){
		//*it ="haha";
//	}
	
	for(;it<vec.cend();it++){
		cout<<*it<<endl;
    }
    
    
    vector<int> vec1{10, 20, 30, 40, 50};
    auto first = vec1.rbegin();
    auto last = vec1.rend();
    while (first != last)
    {
        cout << *first << " ";
        ++first;
    }
    cout << "\n";
    return 0;
}
