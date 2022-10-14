#include<bits/stdc++.h>

using namespace std;
int MOD = 100000007;

/*
我们用 f[i] 表示以 s[i] 为最后一个字符的子序列的数目。

如果子序列中只有 s[i] 这一个字符，那么有一种方案；

如果子序列中至少有两个字符，那么我们可以枚举倒数第二个字符来进行状态转移。
容易想到的是：倒数第二个字符可以选择 s[0], s[1],..... s[i-1] 中的某一个，这样就可以得到如下的状态转移方程：

f[i] = f[0] + f[1] + ...+ f[i-1]

然而这样做会产生重复计数。如果 s[j_0]s[j 
0
?
 ] 和 s[j_1]s[j 
1
?
 ] 这两个字符不相同，那么 f[j_0]f[j 
0
?
 ] 和 f[j_1]f[j 
1
?
 ] 对应的子序列是两个不相交的集合；但如果 s[j_0]s[j 
0
?
 ] 和 s[j_1]s[j 
1
?
 ] 这两个字符相同，那么 f[j_0]f[j 
0
?
 ] 和 f[j_1]f[j 
1
?
 ] 对应的子序列会包含重复的项。最简单的一个重复项就是只含有一个字符的子序列 s[j_0]s[j 
0
?
 ] 或者 s[j_1]s[j 
1
?
 ] 本身。

那么我们该如何防止重复计数呢？可以发现，如果 j_0<j_1j 
0
?
 <j 
1
?
 ，那么 f[j_0]f[j 
0
?
 ] 一定是 f[j_1]f[j 
1
?
 ] 的一个真子集。这是因为：

每一个以 s[j_0]s[j 
0
?
 ] 为最后一个字符的子序列，都可以把这个字符改成完全相同的 s[j_1]s[j 
1
?
 ]，计入到 f[j_1]f[j 
1
?
 ] 中。

因此，对于每一种字符，我们只需要找到其最后一次出现的位置（并且在位置 ii 之前），并将对应的 ff 值累加进 f[i]f[i] 即可。由于本题中字符串只包含小写字母，我们可以用 \textit{last}[k]last[k] 记录第 k~(0 \leq k < 26)k?(0≤k<26) 个小写字母最后一次出现的位置。如果它还没有出现过，那么 \textit{last}[k] = -1last[k]=?1。这样我们就可以写出正确的状态转移方程：

f[i] = \sum_{0\leq k<26,~ \textit{last}[k] \neq -1} f[\textit{last}[k]]
f[i]= 
0≤k<26,?last[k] 

?
 =?1
∑
?
 f[last[k]]

将这两种情况合并在一起，最终的状态转移方程即为：

f[i] = 1 + \sum_{0\leq k<26,~ \textit{last}[k] \neq -1} f[\textit{last}[k]]
f[i]=1+ 
0≤k<26,?last[k] 

?
 =?1
∑
?
 f[last[k]]

在计算完 f[i]f[i] 后，我们需要记得更新对应的 \textit{last}last 项。最终的答案即为：

\sum_{0\leq k<26,~ \textit{last}[k] \neq -1} f[\textit{last}[k]]
0≤k<26,?last[k] 


 =?1
∑ f[last[k]]



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
