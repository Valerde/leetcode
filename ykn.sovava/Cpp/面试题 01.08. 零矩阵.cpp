#include<bits/stdc++.h>
using namespace std;
/*��дһ���㷨����M �� N������ĳ��Ԫ��Ϊ0���������ڵ����������㡣*/
void setZeroes(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	vector<int> row(n,false);
	vector<int> col(m,false);
	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++) {
			if(matrix[i][j]==0) {
				row[i]= true;
				col[j]=true;
			}
		}

	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++) {
			if(row[i]||col[j]) matrix[i][j]=0;
			
		}


}

int main() {
	vector<vector<int>> matrix { {1,1,1},{1,0,1},{1,1,1}};
		int n = matrix.size();
	int m = matrix[0].size();
	setZeroes(matrix);
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

//˫��Ƿ�
int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false, flag_row0 = false;
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                flag_col0 = true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (!matrix[0][j]) {
                flag_row0 = true;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (flag_col0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (flag_row0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

//���ߣ�LeetCode-Solution
//���ӣ�https://leetcode.cn/problems/zero-matrix-lcci/solution/ling-ju-zhen-by-leetcode-solution-7ogg/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע�������� 
