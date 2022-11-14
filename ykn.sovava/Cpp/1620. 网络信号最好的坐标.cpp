#include<bits/stdc++.h>
using namespace std;
vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {

	int xmax = -1,ymax = -1,xmin = 101,ymin = 101;

	for(auto&& tower:towers) {
		xmax = max(xmax,tower[0]);
		ymax = max(ymax,tower[1]);
		xmin = min(xmin,tower[0]);
		ymin = min(ymin,tower[1]);
	}
	int rx = 0, ry = 0;
	int maxsign = 0;
	for(int i = xmin; i<= xmax; i++) {
		for(int j = ymin; j <= ymax; j++) {

			int sign = 0;
			for(auto&& tower:towers) {
				int temp = (tower[0]-i)*(tower[0]-i)+(tower[1]-j)*(tower[1]-j);
				if(radius*radius>=temp) {
					sign+=floor((double)tower[2])/(1+sqrt((double)temp));

				}
			}
			if(maxsign<sign) {
				rx = i;
				ry = j;
				maxsign = sign;
			}
		}
	}

	return vector {rx,ry};
}
