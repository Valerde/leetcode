#include<cstdio>

int find( int L[1005][2],int n, int xx,int yx){
	int  i =0;
	for(i = 0;i<n;i++){
		if(L[i][0]==xx&&L[i][1]==yx)
			return 1;
	}
	return 0;
}

int main(void){
	int n = 0,l = 0 , s = 0;
	int L[1005][2];
	int S[52][52];
	scanf("%d%d%d",&n,&l,&s);
	

	int i = 0 , j = 0 , k = 0 , time = 0;
	for(i = 0;i <n;i++){
		scanf("%d%d",&L[i][0],&L[i][1]);
	}
	
	for(i = 0; i <= s ; i++){
		for(j = 0 ; j<=s ;j++){
			scanf("%d",&S[s-i][j]);
		}
	}

	
	for(i = 0 ; i<n ; i++){
		int flag = 0;
		int x = L[i][0],y = L[i][1];
		for(j = 0; j<=s;j++){
			for(k = 0;k<=s ; k++){
				if(x+j>l||y+k>l) {
					flag = 1;
					break;
				}
				if(S[j][k]!=0){
					if(find( L,n,x+j,y+k)==0){
						flag = 1;
						break;
					}
				}else{
					if(find(L,n,x+j,y+k)==1){
						flag = 1;
						break;
					}
				}
				
				
			}
			if(flag == 1){
				break;
			}
		}
		if(flag == 0){
			time++;
		}
	}
	
	
	printf("%d",time);
	
	
	return 0;
	
}
