#include<bits/stdc++.h>
using namespace std;

/**
给定一个平衡括号字符串S，按下述规则计算该字符串的分数：

() 得 1 分。
AB 得A + B分，其中 A 和 B 是平衡括号字符串。
(A) 得2 * A分，其中 A 是平衡括号字符串。


*/

int scoreOfParentheses(string s) {


	stack<int> stc;
	stc.push(0);
	for(int i = 0 ; i < s.size() ; i++ ) {
		if(s[i]=='(') {
			stc.push(0);
		} else {
			int v = stc.top();
			stc.pop();
			stc.top()+=max(2*v,1);
		}
	}

	return stc.top();
}
/*
我们把平衡字符串 ss 看作是一个空字符串加上 ss 本身，并且定义空字符串的分数为 00。使用栈 \textit{st}st 记录平衡字符串的分数，在开始之前要压入分数 00，表示空字符串的分数。

在遍历字符串 ss 的过程中：

遇到左括号，那么我们需要计算该左括号内部的子平衡括号字符串 AA 的分数，我们也要先压入分数 00，表示 AA 前面的空字符串的分数。

遇到右括号，说明该右括号内部的子平衡括号字符串 AA 的分数已经计算出来了，我们将它弹出栈，并保存到变量 vv 中。如果 v = 0v=0，那么说明子平衡括号字符串 AA 是空串，(A)(A) 的分数为 11，否则 (A)(A) 的分数为 2v2v，然后将 (A)(A) 的分数加到栈顶元素上。

遍历结束后，栈顶元素保存的就是 ss 的分数。

*/




/*
根据题意，ss 的分数与 11 分的 ()() 有关。对于每个 ()()，它的最终分数与它所处的深度有关，如果深度为 \textit{bal}bal，那么它的最终分数为 2^\textit{bal}2
bal 。我们统计所有 ()() 的最终分数和即可。

*/

int scoreOfParentheses(string s) {

	int n = s.size(),res = 0;
	deep = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '(') deep++;
		if(s[i] == ')')deep--;
		if(s[i]=='('&&s[i+1]==')') res+=1<<(deep-1);
	}
	
	return res;

}


int main() {

}
