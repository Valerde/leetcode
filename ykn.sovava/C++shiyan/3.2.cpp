#include<iostream>
#include<string>
#include<vector>
using namespace std;
void mystrchr(char string[], char c,vector<int>&place) {
	int len = strlen(string);
	int i;
	for (i = 0; i < len; i++) {
		if (string[i] == c)
			place.push_back(i);
	}
}

int main(void) {
	char string[50],c;
	int i;
	vector<int>place;
	cout << "enter the string:";
	cin >> string;
	cout << "enter the letter:";
	cin >> c;
	mystrchr(string, c, place);
	if (place.empty())
		cout << -1;
	else
		for (i = 0; i < place.size(); i++)
			cout << place[i] +1 << " ";
	return 0;
}