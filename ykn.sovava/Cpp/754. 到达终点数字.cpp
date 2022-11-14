#include<bits/stdc++.h>
using namespace std;
int reachNumber(int target) {
	target = abs(target);
	int i = 0,sum = 0;
	for(; sum<target; i++)sum+=i;
	i--;
	if(sum == target) return i;

	if((sum-target)%2==0) return i;
	else {
		i++;
		sum+=i;
		if((sum-target)%2==0)return i;
		else return i+1;
	}
}

