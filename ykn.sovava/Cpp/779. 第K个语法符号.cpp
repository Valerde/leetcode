#include<bits/stdc++.h>

using namespace std;
//�����ڵ�һ������д��һ�� 0����������ÿһ�У���ǰһ���е�0�滻Ϊ01��1�滻Ϊ10��
int fuck(int n, int k) {
	//if(k==0) return 0;
	if(n == 1) return 0;

	int temp = fuck(n-1 , k/2);
	if(temp == 1) {
		if(k%2==0)return 1;
		else if(k%2==1) return 0;
	} else if(temp ==0) {
		if(k%2==0) return 0;
		else if(k%2==1) return 1;
	}
	return 0;
}
int kthGrammar(int n, int k) {
	k=k-1;
	return fuck(n,k);
}
//3 1




int fuck(int n, int k){
	if(n == 1||k==0) return 0;
	return (k%2)^fuck(n-1 , k/2);
}
int kthGrammar(int n, int k) { 
    return fuck(n,k-1);
}




    int kthGrammar(int n, int k) {
        // return __builtin_popcount(k - 1) & 1;
        k--;
        int res = 0;
        while (k > 0) {
            k &= k - 1;
            res ^= 1;
        }
        return res;
    }

