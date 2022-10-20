#include<bits/stdc++.h>
using namespace std;
/*
一个酒店里有n个房间，这些房间用二维整数数组rooms表示，
其中rooms[i] = [roomIdi, sizei]表示有一个房间号为roomIdi的房间且它的面积为sizei。每一个房间号roomIdi保证是 独一无二?的。

同时给你m个查询，用二维数组queries表示，其中queries[j] = [preferredj, minSizej]。
第个查询的答案是满足如下条件的房间id：

房间的面积至少为minSizej，且abs(id - preferredj)的值最小，其中abs(x)是x的绝对值。
如果差的绝对值有相等的，选择最小的id。如果没有满足条件的房间，答案为 -1。

请你返回长度为 k的数组answer，其中answer[j]为第j个查询的结果。


*/

vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
	int n = rooms.size();
	int m = queries.size();

	for(int i = 0; i<m; i++) queries[i].push_back(i);

	sort(rooms.begin(),rooms.end(),[&](vector<int> &a,vector<int> &b) {
		return a[1]>b[1];
	});
	sort(queries.begin(),queries.end(),[&](vector<int> &a,vector<int> &b) {
		return a[1]>b[1];
	});

	vector<int> res(m,0);
	set<int> s;
	s.insert(-1e9);
	s.insert(1e9);

	int cur = 0;
	for(auto& val:queries) {
		int id = val[0];
		int ms = val[1];
		int idx = val[2];
		while(cur<n&&rooms[cur][1]>=ms) {
			s.insert(rooms[cur][0]);
			cur++;
		}
		auto it = s.lower_bound(id);
		int a = *it--;
		int b = *it;
		int tempMin =(abs(b - id) <= abs(a - id)) ? b : a;
		res[idx] = (abs(tempMin)==1e9)?-1:tempMin;
	}
	return res;
}
//vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
//        int n = rooms.size();
//        int k = queries.size();
//        /* 将查询下标存入query */
//        for (int i = 0; i < k; i++) {
//            queries[i].push_back(i);
//        }
//        /* 按房间大小从大到小排序 */
//        sort(rooms.begin(), rooms.end(), [&](vector<int> a, vector<int> b) {
//            return a[1] > b[1];
//        });
//        sort(queries.begin(), queries.end(), [&](vector<int> a, vector<int> b) {
//            return a[1] > b[1];
//        });
//
//        set<int> st;
//        st.insert(-1e9); /* 提前存入一个最小值和一个最大值, 防止空指针特判 */
//        st.insert(1e9);
//        vector<int> ans(k);
//        int cur = 0;
//        /* 从大到小处理查询 */
//        for (auto &q : queries) {
//            int id = q[0], size = q[1], idx = q[2];
//            /* 满足条件的房间, 房间id放入set中 */
//            while (cur < n && rooms[cur][1] >= size) {
//                st.insert(rooms[cur][0]);
//                cur++;
//            }
//            /* 二分法寻找最接近id的房间编号 */
//            auto it = st.lower_bound(id);
//            int a = *it--;
//            int b = *it;
//            int minIdx = (abs(b - id) <= abs(a - id)) ? b : a;
//            ans[idx] = (abs(minIdx) == 1e9) ? -1 : minIdx;
//        }
//        return ans;
//
//}
