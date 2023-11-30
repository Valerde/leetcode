#include <iostream>
#include <stdio.h>

using namespace std;

const int N = 1e5;
int a[N];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int mina = a[0], maxa = a[n - 1];
    if(mina > maxa) swap(mina, maxa);
    char c=' ';
    if(n % 2 == 1) {
        printf("%d %d %d", maxa, a[n / 2], mina);
    } else {
        if((a[n / 2 - 1] + a[n / 2]) % 2 == 1)
            printf("%d%c%.1lf%c%d", maxa,c, (double)((a[n / 2 - 1] + a[n / 2]) / 2.0),c, mina);
        else
            printf("%d%c%d%c%d", maxa,c, (a[n / 2 - 1] + a[n / 2]) / 2,c, mina);
    }

    return 0;
}
