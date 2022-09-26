#include<bits/stdc++.h>
using namespace std;
/*
我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，
我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。

如果一个数的每位数字被旋转以后仍然还是一个数字，?则这个数是有效的。
0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方（
在这种情况下，它们以不同的方向旋转，换句话说，2 和 5 互为镜像）；
6 和 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。

现在我们有一个正整数?N, 计算从?1 到?N 中有多少个数?X 是好数？

*/


// 判断一个数是不是好数 , 判断这个数每个位是不是只含1,2,5,6,8,9,0,    且至少含一个2,5,6,9
bool isGood(int num) {
	int temp = num;
	bool flag = false;
	while(temp!=0) {
		int dis = temp%10;
		if(dis==3||dis==4||dis==7) return false;
		if(dis == 2||dis==5||dis==6||dis==9) flag=true;
		temp/=10;
	}
	if(flag) return true;
	return false;


}


int rotatedDigits(int n) {
	int cnt = 0;
	for(int i =  1; i<=n; i++) {
		if(isGood(i)) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	cout<<rotatedDigits(10);
}
