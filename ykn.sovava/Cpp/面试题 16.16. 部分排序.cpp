#include<bits/stdc++.h>
using namespace std;
//思路 左侧最大值大于中间最小值
//     右侧最小值小于中间最大值
vector<int> subSort(vector<int>& array) {
        if(array.size() == 0||array.size() == 1) return vector{-1,-1};
        	int ma = INT_MIN;
	int mi = INT_MAX;
	int len = array.size();
	int last = 0 , first = 0;
	for(int i = 0; i < array.size(); i++) {
		if(array[i] < ma ) {
			last = i;
		} else {
			ma = max(ma,array[i]);
		}

		if(array[len-i-1] >mi) {
			first = len-i-1;
		} else {
			mi = min(mi,array[len-i-1]);
		}
	}
    if(first == 0&&last == 0) return vector{-1,-1};
	return vector{first,last};
    }
