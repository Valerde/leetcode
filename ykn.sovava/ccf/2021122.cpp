#include<cstdio>
#include<cmath>
int main() {
	long n;
	long N;
	scanf("%ld %ld", &n, &N);
	long long r = N/(n+1);
	long long a[100010];
	a[0] = 0;
	for(int i=1; i<=n; i++) {
		scanf("%lld", &a[i]);
	}
	a[n+1] = N;
	
	long long fx, gx; //fx,gx为当前计算的函数值
	long long dr = r; //dr为内层循环每次要移动的位次 
	long long ddr = 0; //用于处理边界情况时的临时变量 
	int flag = 0; //用于标记dr是否改变 
	long long error = 0;
	//以a[i]的值作为外层循环的界限 
	for(long long i=0; i<=n; i++) {
		fx = i;
		//在每段a[i]与 a[i+1]的间隔中，gx的值以r为间隔而变化 
		for(long long j=a[i]; j<a[i+1]; j=j+dr){
			gx = j/r;
			//上一个边界情况之后，上一段g(x)相等段中还有遗留未计算的部分，对其进行处理 
			if(flag == 1) { 
				dr = ddr;
				flag = 0; //标记边界情况已处理完毕 
			}else {
				dr = r; //边界情况处理完之后，重新将循环间隔变回r 
			}
			//当前段处于a[i]和a[i+1]中间，直接计算error值 
			if(j+dr-1 < a[i+1]) {
				error += abs(fx-gx)*dr;
			}else {  //j靠近a[i+1]的边界情况，即 j+dr-1 >= a[i+1]时 
				error += abs(fx-gx)*(a[i+1]-j);
				ddr = dr-(a[i+1]-j); //记录当前g(x)值相同的长度为r的段内，尚未计算error值部分的长度 
				flag = 1; //标记当前段内有尚未计算error值的部分 
			}
		}
	}
	printf("%lld", error);

	return 0;
}
