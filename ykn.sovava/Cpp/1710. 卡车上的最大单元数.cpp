#include<bits/stdc++.h>
using namespace std;
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
	sort(boxTypes.begin(),boxTypes.end(),[](vector<int> &a,vector<int> &b) {
		return a[1]>b[1];
	});
	int res = 0;
	for(auto&& boxType: boxTypes) {
		int numberOfBox = boxType[0], numberOfUnitsPerBox = boxType[1];
		if(numberOfBox<truckSize) {
			res+=numberOfBox* numberOfUnitsPerBox;
			truckSize -= numberOfBox;
		} else {
			res+=truckSize*numberOfUnitsPerBox;
			break;
		}
	}
	return res;

}
