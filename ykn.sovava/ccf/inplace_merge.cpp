#include <iostream>
#include <algorithm>
using namespace std;
int main() 
{
	cout << "àË¿ÍÍø(www.haicoder.net)\n" << endl;	
	int first[] = { 5,10,15,20,25,7,17,27,37,47,57 };
    inplace_merge(first, first + 5,first +11);
    for (int i = 0; i < 11; i++)
    {
        cout << first[i] << " ";
    }
    cout << endl;
    return 0;
}
