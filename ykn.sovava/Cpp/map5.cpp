#include<map>
#include<iostream>
using namespace std;
int main() {
	map<string,string> map1;
	pair<string,string> pair1("ykn","uabi");
	pair<map<string,string>::iterator,bool> ret;
	
	ret = map1.insert(pair1);
	cout<<"ret.iter = <{"<<ret.first->first<<" , "<<ret.first->second<<"}>"<<ret.second<<endl;
	ret = map1.insert(pair1);
	cout<<"ret.iter = <{"<<ret.first->first<<" , "<<ret.first->second<<"}>"<<ret.second<<endl;
	
	
	ret = map1.insert({"cjq","dauabi"});
	cout<<"ret.iter = <{"<<ret.first->first<<" , "<<ret.first->second<<"}>"<<endl;
	
	
	//��������ʼ�� map ����
    std::map<string, string>mymap;
    //ָ���� map ���������ֵ��
    map<string, string>::iterator iter = mymap.emplace_hint(mymap.begin(),"CPP�̳�", "https://haicoder.net/cpp/cpp-tutorial.html");
    cout << iter->first << " " << iter->second << endl;
    iter = mymap.emplace_hint(mymap.begin(), "C���Խ̳�", "https://haicoder.net/c/c-tutorial.html");
    cout << iter->first << " " << iter->second << endl;
    //����ʧ������
    iter = mymap.emplace_hint(mymap.begin(), "CPP�̳�", "https://haicoder.net/cpp/cpp-tutorial.html");
    cout << iter->first << " " << iter->second << endl;
	return 0;
}
