#include<bits/stdc++.h>
using namespace std;
bool checkOnesSegment(string s) {
	return s.find("01") == -1;
}

select player_id,min(event_date) as first_login
from Activity
group by player_id;
