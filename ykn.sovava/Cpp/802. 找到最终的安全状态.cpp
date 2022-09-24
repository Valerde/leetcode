
/*

有一个有 n 个节点的有向图，节点按 0 到 n - 1 编号。图由一个 索引从 0 开始 的 2D 整数数组?graph表示，?graph[i]是与节点 i 相邻的节点的整数数组，这意味着从节点 i 到?graph[i]中的每个节点都有一条边。

如果一个节点没有连出的有向边，则它是 终端节点 。如果没有出边，则节点为终端节点。如果从该节点开始的所有可能路径都通向 终端节点 ，则该节点为 安全节点 。

返回一个由图中所有 安全节点 组成的数组作为答案。答案数组中的元素应当按 升序 排列。

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
	//flag[i] 为1 表示该节点为终端节点
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
// 以上方法超时

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


//三色标记法 , dfs
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
	//flag[i] 为1 表示该节点为终端节点
	int n = graph.size();
	vector<int> color(n);

	//	0:白色 , 该节点未被访问
	//  1:灰色 , 该节点位于递归栈中 , 或在环中
	//  2.  黑色 , 该节点为安全节点
	/*当我们首次访问一个节点时，将其标记为灰色，并继续搜索与其相连的节点。

	如果在搜索过程中遇到了一个灰色节点，则说明找到了一个环，此时退出搜索，栈中的节点仍保持为灰色，
	这一做法可以将「找到了环」这一信息传递到栈中的所有节点上。

	如果搜索过程中没有遇到灰色节点，则说明没有遇到环，那么递归返回前，
	我们将其标记由灰色改为黑色，即表示它是一个安全的节点。

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
