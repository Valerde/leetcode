#include<bits/stdc++.h>

using namespace std;
int MOD = 100000007;

/*
������ f[i] ��ʾ�� s[i] Ϊ���һ���ַ��������е���Ŀ��

�����������ֻ�� s[i] ��һ���ַ�����ô��һ�ַ�����

����������������������ַ�����ô���ǿ���ö�ٵ����ڶ����ַ�������״̬ת�ơ�
�����뵽���ǣ������ڶ����ַ�����ѡ�� s[0], s[1],..... s[i-1] �е�ĳһ���������Ϳ��Եõ����µ�״̬ת�Ʒ��̣�

f[i] = f[0] + f[1] + ...+ f[i-1]

Ȼ��������������ظ���������� s[j_0]s[j 
0
?
 ] �� s[j_1]s[j 
1
?
 ] �������ַ�����ͬ����ô f[j_0]f[j 
0
?
 ] �� f[j_1]f[j 
1
?
 ] ��Ӧ�����������������ཻ�ļ��ϣ������ s[j_0]s[j 
0
?
 ] �� s[j_1]s[j 
1
?
 ] �������ַ���ͬ����ô f[j_0]f[j 
0
?
 ] �� f[j_1]f[j 
1
?
 ] ��Ӧ�������л�����ظ������򵥵�һ���ظ������ֻ����һ���ַ��������� s[j_0]s[j 
0
?
 ] ���� s[j_1]s[j 
1
?
 ] ����

��ô���Ǹ���η�ֹ�ظ������أ����Է��֣���� j_0<j_1j 
0
?
 <j 
1
?
 ����ô f[j_0]f[j 
0
?
 ] һ���� f[j_1]f[j 
1
?
 ] ��һ�����Ӽ���������Ϊ��

ÿһ���� s[j_0]s[j 
0
?
 ] Ϊ���һ���ַ��������У������԰�����ַ��ĳ���ȫ��ͬ�� s[j_1]s[j 
1
?
 ]�����뵽 f[j_1]f[j 
1
?
 ] �С�

��ˣ�����ÿһ���ַ�������ֻ��Ҫ�ҵ������һ�γ��ֵ�λ�ã�������λ�� ii ֮ǰ����������Ӧ�� ff ֵ�ۼӽ� f[i]f[i] ���ɡ����ڱ������ַ���ֻ����Сд��ĸ�����ǿ����� \textit{last}[k]last[k] ��¼�� k~(0 \leq k < 26)k?(0��k<26) ��Сд��ĸ���һ�γ��ֵ�λ�á��������û�г��ֹ�����ô \textit{last}[k] = -1last[k]=?1���������ǾͿ���д����ȷ��״̬ת�Ʒ��̣�

f[i] = \sum_{0\leq k<26,~ \textit{last}[k] \neq -1} f[\textit{last}[k]]
f[i]= 
0��k<26,?last[k] 
��
?
 =?1
��
?
 f[last[k]]

������������ϲ���һ�����յ�״̬ת�Ʒ��̼�Ϊ��

f[i] = 1 + \sum_{0\leq k<26,~ \textit{last}[k] \neq -1} f[\textit{last}[k]]
f[i]=1+ 
0��k<26,?last[k] 
��
?
 =?1
��
?
 f[last[k]]

�ڼ����� f[i]f[i] ��������Ҫ�ǵø��¶�Ӧ�� \textit{last}last ����յĴ𰸼�Ϊ��

\sum_{0\leq k<26,~ \textit{last}[k] \neq -1} f[\textit{last}[k]]
0��k<26,?last[k] 
��

 =?1
�� f[last[k]]



*/
int distinctSubseqII(string s) {
	int n = s.size();
	vector<int> f(n,1);
	vector<int> last(26,-1);
	for(int i = 0; i<s.size(); i++) {
		for(int j = 0; j<26; j++) {
			if(last[j]!=-1) f[i]=((f[i]+f[last[j]])%MOD);
		}
		last[s[i]-'a']=i;
	}

	int ans = 0;

	for(int i = 0; i<26; i++) {

		if(last[i]!=-1)
			ans=(ans+f[last[i]])%MOD;
	}
	return ans;
}


int MOD = 1000000007;
int distinctSubseqII(string s) {
    vector<int> g(26, 0);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int total = 1;
            for (int j = 0; j < 26; ++j) {
                total = (total + g[j]) % MOD;
            }
            g[s[i] - 'a'] = total;
        }
        
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + g[i]) % MOD;
        }
        return ans;

}
