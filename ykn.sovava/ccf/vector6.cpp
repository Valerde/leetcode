#include<vector>
#include<iostream>
using namespace std;

int main(){
	vector<string> vec{"ykn","ui","uabi"};
	
	for(int i = 0;i<vec.size();i++){
		cout << vec[i] << endl;
	}
	
	cout<<"--------"<<endl;
	for(auto&& str:vec){
		cout << str << endl;
	}
	
	cout << "----"<<endl;
	for(auto i = vec.begin();i<vec.end();i++){
		
		string stri = *i;
		cout << stri<<endl;
	}
	
	return 0;
}
