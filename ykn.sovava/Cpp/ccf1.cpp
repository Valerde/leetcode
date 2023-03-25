#include<bits/stdc++.h>
using namespace std;
class cmp {
	public:
		bool operator()(int a,int b) {
			return a>b;
		}
};

int comp(vector<int> a,vector<int> b) {
	if(a[0]==b[0]) return a[1]>b[1];
	return a[0]>b[0];
}
void mysort() {
	vector<vector<int> > v {
		{1,2},
		{1,3},
		{2,1},
		{3,2}
	};
	sort(v.begin(),v.end(),[&](vector<int> a,vector<int> b) {
//		return a[0]==b[0]?a[1]>b[1]:a[0]>b[0];
		if(a[0]==b[0]) return a[1]>b[1];
		return a[0]>b[0];
	});
	for(int i = 0; i<4; i++) {
		cout<< v[i][0]<<" "<<v[i][1]<<endl;
	}
}
void reverse() {
	vector<int> v {1,2,3,4,5,6};
	reverse(v.begin(),v.end());
	for(auto &it:v) cout<<it<<" ";
	cout<<endl;
}

void setLessTest() {
	set<int,greater<int>> M;

	M.insert(1960);

	M.insert(1952);

	M.insert(1771);

	M.insert(1812);

	M.insert(1960);

	M.insert(2000);

	set<int,greater<int>>::iterator N = M.begin();

	cout<<"Number of elements "<<M.size()<<endl;

	cout<<"The elements are:"<<endl;

	while(N != M.end())

	{

		cout<<*N<<endl;

		++N;

	}
}

void priorityTest() {
	priority_queue<int,vector<int>,less<int> > pq;
	pq.push(1);
	pq.push(3);
	pq.push(2);
	while(pq.empty()==false) {
		cout<<pq.top()<<endl;
		pq.pop();
	}
}

void stackTest() {
	stack<int> stk;
	for(int i = 0; i<10; i++) {
		stk.emplace(i);
	}
	while(!stk.empty()) {
		auto it = stk.top();
		cout<<it<<endl;
		stk.pop();
	}
}

void test1() {
	cout<<" ----- "<<endl;
	map<int,int> m;
	for(int i = 0; i<10; i++) {
		m.emplace(i,i*i);
	}
	for(auto it = m.begin(); it!=m.end(); it++) {
		cout<<it->first<<" "<<it->second<<endl;
	}
	cout<<" ----- "<<endl;
	auto it = m.begin();
	while(it!=m.end()) {
		m.erase(it++);
	}
	for(auto it = m.begin(); it!=m.end(); it++) {
		cout<<it->first<<" "<<it->second<<endl;
	}
	cout<<" ----- "<<endl;
}

void test2() {
	cout<<" --set--- "<<endl;
	set<int> m;
	for(int i = 0; i<10; i++) {
		m.emplace(i*i);
	}
	for(auto it = m.begin(); it!=m.end(); it++) {
		cout<<*it<<endl;
	}
	cout<<" ----- "<<endl;
	auto it = m.begin();
	while(it!=m.end()) {
		m.erase(it++);
	}
//	for(auto it = m.begin(); it!=m.end(); it++) {
//		m.erase(it);
//	}
	for(auto it = m.begin(); it!=m.end(); it++) {
		cout<<*it<<endl;
	}
	cout<<" --set--- "<<endl;
}


void findTest1() {
	vector<int> v;
	for(int i =0 ; i<10; i++) {
		v.push_back(i*i);
	}
//	auto it = v.find(16);
	auto it = find(v.begin(),v.end(),16);
	cout<<" len = " <<it-v.begin()<<endl;
}
void main() {
	//创建空 map 容器，默认根据个键值对中键的值，对键值对做降序排序
	unordered_map<string,string> myMap;
	//调用 emplace() 方法，直接向 myMap 容器中指定位置构造新键值对
	myMap.emplace("C语言教程","http://c.biancheng.net/c/");
	myMap.emplace("Python教程", "http://c.biancheng.net/python/");
	myMap.emplace("STL教程", "http://c.biancheng.net/stl/");

	if(myMap.find("STL教程")!=myMap.end()) {
		cout<<myMap["STL教程"]<<"key exit"<<endl;
	}

	vector<string> keys;
	for(auto it = myMap.begin(); it!=myMap.end(); it++) {
		keys.push_back(it->first);
	}
	for(auto & key:keys) {
		cout<<key<<" ";
	}


	unordered_set<int> s;
	s.emplace(2);
	s.emplace(3);
	s.emplace(1);
	s.erase(3);
	for(auto it:s) {
		cout<<it<<" "<<s.size();
	}

	cout<<endl;

	unordered_map<int,int> m;
	m[1]++;
	cout<<m[1]<<endl;
	m.emplace(2,3);
	m.erase(2);
//	cout<<m[2]<<endl;
	cout<<"len="<<m.size()<<endl;
	auto it = m.find(1);
	if(it!=m.end())
		cout<<"_"<<it->first<<endl;
//	cout<<m.find(2);


	cout<<endl<<endl;

	vector<int> v {1,2,3,4,5,6};
//	v.erase(4);
	auto&& it1=lower_bound(v.begin(),v.end(),3.5);
	it1=v.erase(it1);
	cout<<*it1<<endl;

//	v.reverse();
	cout<<" is_sorted"<<is_sorted(v.begin(),v.end(),[&](int a,int b) {
		return a<b;
	});

	cout<<" is_sorted"<<is_sorted(v.begin(),v.end(),cmp());
	cout<<endl;


	stack<int> stk;
	stk.push(3);
	stk.emplace(4);
	cout<<stk.top();
	stk.pop();
	cout<<stk.top();


	cout<<endl;

	string str;
	str = "asdf";
	str.push_back('w');
	str.erase(str.begin());
	cout<<str<<endl;


	priority_queue<int,vector<int>,less<int> > pq;
	pq.push(2);
	pq.push(4);
	pq.push(1);
//	int q = pq.top();
	while(pq.size()>0) {
		cout<<pq.top()<<" ";
		pq.pop();
	}

	cout<<"-----"<<endl;
//	findTest1();
//	test1();
//	test2();
//	stackTest();
//	setLessTest();
//	priorityTest();

//	reverse();
	mysort();
//	return 0;
}
