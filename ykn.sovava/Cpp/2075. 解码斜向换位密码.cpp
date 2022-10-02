#include<bits/stdc++.h>
using namespace std;
/*
字符串 originalText 使用 斜向换位密码 ，经由 行数固定 为 rows 的矩阵辅助，加密得到一个字符串 encodedText 。

originalText 先按从左上到右下的方式放置到矩阵中。


先填充蓝色单元格，接着是红色单元格，然后是黄色单元格，以此类推，直到到达 originalText 末尾。箭头指示顺序即为单元格填充顺序。所有空单元格用 ' ' 进行填充。矩阵的列数需满足：用 originalText 填充之后，最右侧列 不为空 。

接着按行将字符附加到矩阵中，构造?encodedText 。


先把蓝色单元格中的字符附加到 encodedText 中，接着是红色单元格，最后是黄色单元格。箭头指示单元格访问顺序。

例如，如果 originalText = "cipher" 且 rows = 3 ，那么我们可以按下述方法将其编码：


蓝色箭头标识 originalText 是如何放入矩阵中的，红色箭头标识形成 encodedText 的顺序。在上述例子中，encodedText = "ch? ?ie? ?pr" 。

给你编码后的字符串 encodedText 和矩阵的行数 rows ，返回源字符串 originalText 。

注意：originalText 不 含任何尾随空格 ' ' 。生成的测试用例满足 仅存在一个 可能的 originalText 。


*/

string decodeCiphertext(string encodedText, int rows) {
	string dt;
	int cols = encodedText.size()/rows;
	int j = 0;
	for(int k = 0; k<cols; k++) {
		for(int i = 0; i<rows; i++) {
			if(j<cols)
				dt+=(encodedText[i*cols+i+j]);

		}
		j++;
	}
	//cout<<dt<<"|";
	string res;
	int qq ;
	for(qq = dt.size()-1; qq>0 ; qq--) {
		if(dt[qq] >='a'&&dt[qq]<='z') {
			break;
		}
	}
	for(int i = 0; i<=qq; i++)
		res+=dt[i];
	return res;
}
string temp_decodeCiphertext(string encodedText, int rows) {
	int cols = encodedText.size() / rows;   // 辅助矩阵的列数
	string res;   // 遍历到的字符
	for (int i = 0; i < cols; ++i) {
		// 从左至右枚举每一条路径
		int r = 0;
		int c = i;
		while (r < rows && c < cols) {
			res.push_back(encodedText[r*cols+c]);
			++r;
			++c;
		}
	}
	// 删去末尾空格
	while (res.size() and res.back() == ' ') {
		res.pop_back();
	}
	return res;

}

int main() {
	cout<<decodeCiphertext("iveo    eed   l te   olc",4)<<"|";
}
