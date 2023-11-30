#include<bits/stdc++.h>
using namespace std;

bool can_reach(int distance, const vector<int>& rocks, int M) {
    int prev_rock = 0;
    int removed_rocks = 0;

    for (int rock : rocks) {
        if (rock - prev_rock < distance) {
            removed_rocks++;
            if (removed_rocks > M)
                return false;
        } else {
            prev_rock = rock;
        }
    }

    return true;
}

int max_shortest_distance(int L, const vector<int>& rocks, int M) {
    vector<int> sorted_rocks = rocks;
    sorted_rocks.push_back(L);
    sort(sorted_rocks.begin(), sorted_rocks.end());

    int left = 1;
    int right = L;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (can_reach(mid, sorted_rocks, M)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    int L ,M ,N;
    cin>>L>>N>>M;
    
    vector<int> rocks ;
    for(int i = 0;i<N;i++){
    	int tmp = 0;
    	cin>>tmp;
    	rocks.push_back(tmp);
    }
    

    int max_distance = max_shortest_distance(L, rocks, M);
    cout << max_distance << std::endl;

    return 0;
}

