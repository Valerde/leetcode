#include<iostream>
#include<utility>
#include<string>
using namespace  std;

int main() {
	pair<string,string> pair1("ykn","usbi");
	pair<string,string> pair2("cjq","dauabi");
	pair<string,string> pair3(make_pair("igtmyu","jiba"));

	cout<<pair1.first<<"-pair-"<<pair1.second<<endl;
	cout<<pair2.first<<"-pair-"<<pair2.second<<endl;
	cout<<pair3.first<<"-pair-"<<pair3.second<<endl;
}
