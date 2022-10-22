#include<bits/stdc++.h>
using namespace std;
int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
	if(start>destination) swap(start , destination);
	
	int uy =0;
	for(int i = start;i<destination;i++) uy+=distance[i];
	int ni = 0;
	for(int i = 0;i<start;i++) ni += distance[i];
	for(int i = destination;i<distance.size();i++) ni+=distance[i];
	return min(uy,ni); 
}
