#include <bits/stdc++.h>
using namespace std;
bool parseBoolExpr(string expression) {
	stack<char> stk;
	for(int i = 0;i<expression.size();i++){
		if(expression[i] ==',') continue;
		else if(expression[i] != ')'){
			stk.push(expression[i]);
		}else{
			char AND = 't',OR = 'f',temp;
			while(stk.top()!='('){
				if(stk.top() == 'f') AND = 'f';
				else if(stk.top() == 't') OR = 't';
				temp = stk.top();
				stk.pop();
			}
			stk.pop();
            char now = stk.top();
            stk.pop();
			if(now == '&') stk.push(AND);
			else if(now == '|')stk.push(OR);
			else if (now == '!') stk.push(temp=='t'?'f':'t');
            
		}
	}
    //cout<<stk.size();
	return stk.top()=='t';
}
