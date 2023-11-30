#include<iostream>
#include<string>
using namespace std;
struct str {
	char str[10];
};
int main(void) {
	struct str ch[5];
	char mid[10];
	int i,j;
	for (i = 0; i < 5; i++) {
		cin >> ch[i].str;
		for (j = 0; j < i; j++) {
			if (strcmp(ch[i].str, ch[j].str) < 0) {
				strcpy_s(mid , ch[i].str);
				strcpy_s(ch[i].str , ch[j].str);
				strcpy_s(ch[j].str , mid);

			}
		}
	}
	cout << "----------out-----------"<<endl;
	for (i = 0; i < 5; i++)
		cout << ch[i].str<<endl;
	return 0;
}