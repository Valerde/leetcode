#include<bits/stdc++.h>
using namespace std;



bool check(vector<vector<char>>& board,vector<vector<int>>& visited,int i,int j,string& word,int k) {
	cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
	if(board[i][j]!=word[k]) return false;
	else if(k==word.length()-1) return true;

	visited[i][j] = true;
	int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
	bool res = false;
	for(int g = 0; g<4; g++) {
		int newi = i+dir[g][0],newj = j+ dir[g][1];
		if(newi>=0 && newi < board.size() && newj>=0 && newj < board[0].size()) {
			if(!visited[newi][newj]) {
				bool flag = check(board,visited,newi,newj,word,k+1);
				if(flag) {
					res = true;
					break;
				}
			}
		}
	}
	visited[i][j] = false;
	return res;
}



bool exist(vector<vector<char>>& board, string word) {
	int n = board.size();
	int m = board[0].size();
	cout<<n<<" "<<m<<endl;
	vector<vector<int>> visited(n,vector<int>(m));
//----------------------------------------------------------
	int h = 0;
	for (const vector<char>& row : board)
		for (const char& c : row) {
			if (c == word[0])
				h += 1;
			else if (c == word.back())
				h -= 1;
		}
	//剪枝，用少的那个。估计是可以剪掉那个刚好很多重复头元素的
	if (h > 0)
		reverse(word.begin(), word.end());
//----------------------------------------------------------

	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			bool flag =  check(board,visited,i,j,word,0);
			if(flag) return true;
		}
	}
	return false;
}
int main() {
	vector<vector<char>> board = {
		{'A','B','C','E'}
		,{'S','F','C','S'}
		,{'A','D','E','E'}
	};
	string word = "ABCCED";

	cout<<exist(board,word);
}
