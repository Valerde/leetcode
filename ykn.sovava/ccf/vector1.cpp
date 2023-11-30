#include<iostream>
#include<vector>
using namespace std;
int main(){
	//创建一个向量存储 int
	vector<int> vec;
	int i;
	
	
	//显示vec的大小
	cout << "vector size = " << vec.size()<<endl;
	
	//推五个值进入向量中
	for(i = 0;i<5;i++){
		vec.push_back(i);
	} 
	
	//显示扩展后的大小
	cout << "extended vector size = "<<vec.size()<<endl;
	
	//访问向量中的五个值
	for(int j = 0;j<5;j++){
		cout<<"value of vec [" <<j<<"]="<<vec[j]<<endl;
	} 
	

	
	//使用迭代器iterator访问值
	vector<int>::iterator v = vec.begin();
	cout<< v[3]<<endl;
	while(v!=vec.end()){
		cout << "value of v = " <<*v << endl;
		v++;
	}
	
	for(v = vec.begin();v!=vec.end();v++){
		cout << "value of v = " <<*v << endl;
	}
	
	return 0;
	 
} 
