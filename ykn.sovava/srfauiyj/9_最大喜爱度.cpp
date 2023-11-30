/*
3．求能获得的最大喜爱度
输入描述：
第一行输入为：能使用的钱的总额 X 和商品种类的总数 N，两个数字通过空格隔开
第二行开始，每行为一个单一的商品，包括的信息是：商品单价 P、该商品个数 amt、该商品喜爱度 fav
示例：
输入：
10 4
2 2 2
5 2 2
4 1 3
9 1 3

输出：
7 2
1 2
3 1
解释：用 10 块钱，最大的喜爱度是7，购买2种商品：
购买 第一种商品2 个，得到的喜爱度是 4；再购买第三种商品 1 个，得到的喜爱度是 3。
*/

;
/*
* 分析：本实验有两个限制条件，即在规定的金额内，规定的物品数量内达到最大的喜爱度。
* dp[money]表示用money多的钱获得的最大喜爱度。
* mem[j]表示在花费为j多钱的情况下新增的商品序号和个数。
* 

*/

#include<iostream>
#include<algorithm>
using namespace std;
int money;
int n;
struct Data {
	int p;
	int amt;
	int fav;
};
Data dat[20];
int dp[50] = { 0 };
struct Mem {
	int num;
	int amt;
};
Mem mem[20];
void setmy() {
	cin >> money >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dat[i].p >> dat[i].amt >> dat[i].fav;
	}

}

int main(void) {
	setmy();
	int temp = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = money; j > dat[i].p; j--) {
			for (int k = 1; k <= dat[i].amt && money - k * dat[i].p >= 0; k++) {
				temp = dp[j];
				dp[j] = max(dp[j], dp[j - k * dat[i].p] + k * dat[i].fav);
				if (dp[j] != temp) {
					mem[j].amt = k;
					mem[j].num = i;
				}
			}
		}
	}
	temp = 0;
	printf("--------------\n");
	for (int i = 0; i <= money; i++) {
		if (mem[i].num == temp) {
			continue;
		}
		printf("%d  %d\n", mem[i].num,mem[i].amt);
		temp = mem[i].num;
	}
	cout << dp[money];
	return 0;
}



