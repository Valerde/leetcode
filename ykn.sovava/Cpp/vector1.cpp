#include<iostream>
#include<vector>
using namespace std;
int main(){
	//����һ�������洢 int
	vector<int> vec;
	int i;
	
	
	//��ʾvec�Ĵ�С
	cout << "vector size = " << vec.size()<<endl;
	
	//�����ֵ����������
	for(i = 0;i<5;i++){
		vec.push_back(i);
	} 
	
	//��ʾ��չ��Ĵ�С
	cout << "extended vector size = "<<vec.size()<<endl;
	
	//���������е����ֵ
	for(int j = 0;j<5;j++){
		cout<<"value of vec [" <<j<<"]="<<vec[j]<<endl;
	} 
	

	
	//ʹ�õ�����iterator����ֵ
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
