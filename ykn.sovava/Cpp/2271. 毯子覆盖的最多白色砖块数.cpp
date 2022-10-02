#include<bits/stdc++.h>
using namespace std;

bool mysort(vector<int> a,vector<int> b) {
	return a[0]<b[0];
}
int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
	int n = tiles.size();
	sort(tiles.begin(),tiles.end());

	int res = -1;
	int i = 0,j = 0,_temp = 0;
	for(int i = 0; i<n; i++) {

		if(i) _temp-= tiles[i-1][1] - tiles[i-1][0] + 1;
		
		for(; j<n; j++) {
			if((tiles[j][1]-tiles[i][0])<carpetLen)
				_temp+=tiles[j][1]-tiles[j][0]+1;
			else {
				break;
			}
		}
		if (j == n) {
			// 此时无法通过右移增加覆盖瓷砖数，更新最大值并返回即可
			res = max(res, _temp);
			return res;
		}
		int extra = max(0, tiles[i][0] + carpetLen - tiles[j][0]);
		res = max(res,_temp+extra);
	}
	return res;
}// 上面代码如果重新对j 赋值 , 会超时O(n2) 
int main() {

	vector<vector<int>> tiles = {{1,5},{10,11},{12,18},{20,25},{30,32}};
	int carpetLen = 10;
	cout<<maximumWhiteTiles(tiles,carpetLen);
}
