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
	
	long long fx, gx; //fx,gxΪ��ǰ����ĺ���ֵ
	long long dr = r; //drΪ�ڲ�ѭ��ÿ��Ҫ�ƶ���λ�� 
	long long ddr = 0; //���ڴ���߽����ʱ����ʱ���� 
	int flag = 0; //���ڱ��dr�Ƿ�ı� 
	long long error = 0;
	//��a[i]��ֵ��Ϊ���ѭ���Ľ��� 
	for(long long i=0; i<=n; i++) {
		fx = i;
		//��ÿ��a[i]�� a[i+1]�ļ���У�gx��ֵ��rΪ������仯 
		for(long long j=a[i]; j<a[i+1]; j=j+dr){
			gx = j/r;
			//��һ���߽����֮����һ��g(x)��ȶ��л�������δ����Ĳ��֣�������д��� 
			if(flag == 1) { 
				dr = ddr;
				flag = 0; //��Ǳ߽�����Ѵ������ 
			}else {
				dr = r; //�߽����������֮�����½�ѭ��������r 
			}
			//��ǰ�δ���a[i]��a[i+1]�м䣬ֱ�Ӽ���errorֵ 
			if(j+dr-1 < a[i+1]) {
				error += abs(fx-gx)*dr;
			}else {  //j����a[i+1]�ı߽�������� j+dr-1 >= a[i+1]ʱ 
				error += abs(fx-gx)*(a[i+1]-j);
				ddr = dr-(a[i+1]-j); //��¼��ǰg(x)ֵ��ͬ�ĳ���Ϊr�Ķ��ڣ���δ����errorֵ���ֵĳ��� 
				flag = 1; //��ǵ�ǰ��������δ����errorֵ�Ĳ��� 
			}
		}
	}
	printf("%lld", error);

	return 0;
}
