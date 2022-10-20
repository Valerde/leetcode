#include<bits/stdc++.h>
using namespace std;
/*
һ���Ƶ�����n�����䣬��Щ�����ö�ά��������rooms��ʾ��
����rooms[i] = [roomIdi, sizei]��ʾ��һ�������ΪroomIdi�ķ������������Ϊsizei��ÿһ�������roomIdi��֤�� ��һ�޶�?�ġ�

ͬʱ����m����ѯ���ö�ά����queries��ʾ������queries[j] = [preferredj, minSizej]��
�ڸ���ѯ�Ĵ����������������ķ���id��

������������ΪminSizej����abs(id - preferredj)��ֵ��С������abs(x)��x�ľ���ֵ��
�����ľ���ֵ����ȵģ�ѡ����С��id�����û�����������ķ��䣬��Ϊ -1��

���㷵�س���Ϊ k������answer������answer[j]Ϊ��j����ѯ�Ľ����


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
//        /* ����ѯ�±����query */
//        for (int i = 0; i < k; i++) {
//            queries[i].push_back(i);
//        }
//        /* �������С�Ӵ�С���� */
//        sort(rooms.begin(), rooms.end(), [&](vector<int> a, vector<int> b) {
//            return a[1] > b[1];
//        });
//        sort(queries.begin(), queries.end(), [&](vector<int> a, vector<int> b) {
//            return a[1] > b[1];
//        });
//
//        set<int> st;
//        st.insert(-1e9); /* ��ǰ����һ����Сֵ��һ�����ֵ, ��ֹ��ָ������ */
//        st.insert(1e9);
//        vector<int> ans(k);
//        int cur = 0;
//        /* �Ӵ�С�����ѯ */
//        for (auto &q : queries) {
//            int id = q[0], size = q[1], idx = q[2];
//            /* ���������ķ���, ����id����set�� */
//            while (cur < n && rooms[cur][1] >= size) {
//                st.insert(rooms[cur][0]);
//                cur++;
//            }
//            /* ���ַ�Ѱ����ӽ�id�ķ����� */
//            auto it = st.lower_bound(id);
//            int a = *it--;
//            int b = *it;
//            int minIdx = (abs(b - id) <= abs(a - id)) ? b : a;
//            ans[idx] = (abs(minIdx) == 1e9) ? -1 : minIdx;
//        }
//        return ans;
//
//}
