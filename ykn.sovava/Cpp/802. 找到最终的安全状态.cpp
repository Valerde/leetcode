
/*

��һ���� n ���ڵ������ͼ���ڵ㰴 0 �� n - 1 ��š�ͼ��һ�� ������ 0 ��ʼ �� 2D ��������?graph��ʾ��?graph[i]����ڵ� i ���ڵĽڵ���������飬����ζ�Ŵӽڵ� i ��?graph[i]�е�ÿ���ڵ㶼��һ���ߡ�

���һ���ڵ�û������������ߣ������� �ն˽ڵ� �����û�г��ߣ���ڵ�Ϊ�ն˽ڵ㡣����Ӹýڵ㿪ʼ�����п���·����ͨ�� �ն˽ڵ� ����ýڵ�Ϊ ��ȫ�ڵ� ��

����һ����ͼ������ ��ȫ�ڵ� ��ɵ�������Ϊ�𰸡��������е�Ԫ��Ӧ���� ���� ���С�

*/
#include<bits/stdc++.h>
using namespace std;

bool dfs1(vector<vector<int>>& graph,int nextNode,vector<bool>& path,vector<bool> flag) {
	if(flag[nextNode]==true) return true;
	if(path[nextNode]==true) return false;
	for(int i = 0; i<graph[nextNode].size(); i++) {
		path[nextNode] = true;
		if(dfs1(graph,graph[nextNode][i],path,flag)) {
			path[nextNode] =false;
		} else {
			return false;
		}
	}
	return true;
}
vector<int> eventualSafeNodes1(vector<vector<int>>& graph) {
	//flag[i] Ϊ1 ��ʾ�ýڵ�Ϊ�ն˽ڵ�
	vector<bool> flag(graph.size(),false);
	vector<int > result;
	for(int  i=0; i<graph.size(); i++) {
		if(graph[i].size()==0)
			flag[i] = true;
	}

	for(int i = 0; i<graph.size(); i++) {
		if(flag[i]==1) {
			result.push_back(i);
			continue;
		}
		result.push_back(i);
		for(int j = 0; j<graph[i].size(); j++) {
			vector<bool> path(graph.size(),false);
			path[i] = true;
			if(dfs1(graph,graph[i][j],path,flag)==false) {
				result.pop_back();
				break;
			}
		}

	}
	return result;
}
// ���Ϸ�����ʱ

bool dfs(vector<vector<int>>& graph,vector<int>& color,int x) {
	if(color[x]>0) return color[x]==2;

	color[x]=1;

	for(int i = 0; i<graph[x].size(); i++) {
		if(!dfs(graph,color,graph[x][i]))
		        return false;
	}

	color[x]= 2;
	return true; 
}


//��ɫ��Ƿ� , dfs
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
	//flag[i] Ϊ1 ��ʾ�ýڵ�Ϊ�ն˽ڵ�
	int n = graph.size();
	vector<int> color(n);

	//	0:��ɫ , �ýڵ�δ������
	//  1:��ɫ , �ýڵ�λ�ڵݹ�ջ�� , ���ڻ���
	//  2.  ��ɫ , �ýڵ�Ϊ��ȫ�ڵ�
	/*�������״η���һ���ڵ�ʱ��������Ϊ��ɫ���������������������Ľڵ㡣

	���������������������һ����ɫ�ڵ㣬��˵���ҵ���һ��������ʱ�˳�������ջ�еĽڵ��Ա���Ϊ��ɫ��
	��һ�������Խ����ҵ��˻�����һ��Ϣ���ݵ�ջ�е����нڵ��ϡ�

	�������������û��������ɫ�ڵ㣬��˵��û������������ô�ݹ鷵��ǰ��
	���ǽ������ɻ�ɫ��Ϊ��ɫ������ʾ����һ����ȫ�Ľڵ㡣

	*/

	function<bool(int)> safe = [&](int x) {
		if (color[x] > 0) {
			return color[x] == 2;
		}
		color[x] = 1;
		for (int y : graph[x]) {
			if (!safe(y)) {
				return false;
			}
		}
		color[x] = 2;
		return true;
	};

	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (dfs(graph,color,i)) {
			ans.push_back(i);
		}
	}
	return ans;




}




int main() {
	vector<vector<int>> graph {{},{0,2,3,},{3},{4},{}};
	vector<int> re = eventualSafeNodes(graph);
	for(int i = 0; i<re.size(); i++) {
		cout<<re[i]<<" ";
	}
}
