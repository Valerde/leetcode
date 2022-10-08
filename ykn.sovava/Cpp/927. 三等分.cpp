#include<bits/stdc++.h>
/*
给定一个由 0 和 1 组成的数组?arr?，将数组分成 ?3?个非空的部分 ，使得所有这些部分表示相同的二进制值。

如果可以做到，请返回任何?[i, j]，其中 i+1 < j，这样一来：

arr[0], arr[1], ..., arr[i]?为第一部分；
arr[i + 1], arr[i + 2], ..., arr[j - 1]?为第二部分；
arr[j], arr[j + 1], ..., arr[arr.length - 1]?为第三部分。
这三个部分所表示的二进制值相等。
如果无法做到，就返回?[-1, -1]。

注意，在考虑每个部分所表示的二进制时，应当将其看作一个整体。例如，[1,1,0]?表示十进制中的?6，而不会是?3。此外，前导零也是被允许的，所以?[0,1,1] 和?[1,1]?表示相同的值。
*/
using namespace std;
vector<int> threeEqualParts(vector<int>& arr) {

	int num = 0;
	for(auto&& a:arr) {
		num+=a;
	}
	if(num%3!=0) return {-1,-1};
	else if (num==0) return {0,2};

	int n = arr.size();
	int partial = num/3;
	int fir = 0, sec = 0 , thi = 0;
	for(int i = 0,cnt = 0; i<n; i++) {
		if(arr[i]) {
			if(cnt==(partial)) sec=i;
			else if(cnt==(2*partial)) thi = i;
			else if(cnt == 0) fir = i;
			cnt++;
		}
	}

	int len = n - thi;
	for(int i = 0; i<len; i++)
		if(arr[fir+i]!=arr[sec+i]||arr[sec+i]!=arr[thi+i]) {
			return {-1,-1};
		}
	return {fir+len-1,sec+len};

}




int main() {

	vector<int> arr {0,1,0,1,1,0,1,1,0,1};

	vector<int> res = threeEqualParts(arr);
	cout<<res[0]<<" "<<res[1];
}

/*
如果存在一种分法使得三个非空部分所表示的二进制值相同，那么最终每一部分 11 的数量一定是相等的。
根据这个思想，我们首先统计数组 \textit{arr}arr 中 11 的个数，把它设为 \textit{sum}sum。
如果 \textit{sum}sum 不能被 33 整除，那么显然不存在正确分法。
否则，每一个部分都应当有 \textit{partial} = \dfrac{\textit{sum}}{3}partial=3sum?  个 11。

我们尝试找到 \textit{arr}arr 中第 11 个 11 出现的位置 \textit{first}first，第 \textit{partial} + 1partial+1 个 11 出现的位置 \textit{second}second 以及第 2 \times \textit{partial} + 12×partial+1 个 11 出现的位置 \textit{third}third。因为每一部分末尾的 00 可以移动到下一部分的首部从而改变二进制值的大小, 所以每一部分的末尾难以界定。但是注意到，数组的末尾是无法改变的，因此区间 [\textit{third}, \textit{arr.length} - 1][third,arr.length?1] 所表示的二进制值可以固定。

设 \textit{len} = \textit{arr.length} - \textit{third}len=arr.length?third，表示二进制值的长度。接下来只需要判断 [\textit{first}, \textit{first} + \textit{len})[first,first+len)、[\textit{second}, \textit{second} + \textit{len})[second,second+len) 和 [\textit{third}, \textit{third} + \textit{len})[third,third+len) 是否完全相同即可。前提是 \textit{first} + \textit{len} \le \textit{second}first+len≤second 并且 \textit{second} + \textit{len} \le \textit{third}second+len≤third。

如果以上三段区间是完全相同的，那么答案就是 [\textit{first} + \textit{len} - 1, \textit{second} + \textit{len}][first+len?1,second+len]。最后需要注意到，如果 \textit{sum} = 0sum=0，我们需要直接返回答案 [0, 2][0,2]（或者其他任意合法答案）。

*/
