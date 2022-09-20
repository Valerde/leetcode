#include<bits/stdc++.h>
using namespace std;
int distributeCandies(vector<int>& candyType) {
return min(unordered_set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2);
}

int main() {
	vector<int> candyType {1,1,1,2,2,3,3};
	cout<<distributeCandies(candyType);
}
