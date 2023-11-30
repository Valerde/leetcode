#include<cstdio>
#include<cmath>
int main(void){
	int n = 0;
	int a[1005];
	scanf("%d",&n);
	//printf("%d",n);
	int i = 0 , temp = 0 ;
	double total = 0;
	for(i=0;i<n;i++)
	{
		
		scanf("%d",&temp);
		a[i] = temp;
		total+=temp;
	}
	//printf("%d",a[3]);
	double aba = total/n;
	double D=0;
	for(i = 0;i<n;i++){
		D += (a[i]-aba)*(a[i]-aba);
	}
	D = D/n;
	D = sqrt(D);
	//printf("%f",D);
	
	for(i = 0; i < n ; i++){
		printf("%f",(a[i]-aba)/D);
	}
	return 0;
	
} 
