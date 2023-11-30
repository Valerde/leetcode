#include<iostream>
#include<cstdio>
using namespace std;
const int mov[4][2] = { {0,1 }, {0, -1},{ -1, 0},{ 1, 0} };
int size = 12;
int a[12][12];//方格状况
int save[12 * 12][2];//[当前已经遍历过的点的序号][横纵坐标】
int path[12 * 12];//【内为当前遍历序号】存储的内容为上一序号
int a1, b1;//出发点坐标
int a2, b2;//终点坐标
int countlen = 0;
bool judge(int i, int j) {
    if (a[i][j] == 1)
        return false;
    return true;
}
void coutmy(int a) {
    if (a == 1)
        return;
    countlen++;
    coutmy(path[a]);
    cout << "-->" <<"("<< save[a][0]+1 << "," << save[a][1]+1<<")";
}
void solution() {
    int sign1=0, sign2=1;//sign1为空处遍历过的序号，sign2为正确路径序号path[]
    path[sign2] = sign1;//第一个遍历的前级肯定为出发点
    save[1][0] = a1; save[1][1] = b1;
    a[a1][b1] = 1;//出发点肯定走完了设为1
    do {
        sign1++;
        for (int i = 0; i < 4; i++) {
            if (judge(save[sign1][0] + mov[i][0], save[sign1][1] + mov[i][1])) {
                sign2++;
                path[sign2] = sign1;
                save[sign2][0] = save[sign1][0] + mov[i][0];
                save[sign2][1] = save[sign1][1] + mov[i][1];
                a[save[sign2][0]][save[sign2][1]] = 1;
            }
            if (save[sign2][0] == a2-1 && save[sign2][1] == b2-1) {
                int count = 0;
                cout << "(" << a1 << "," << b1 << ")";
                coutmy(sign2);
                cout << "步长为" << countlen;
                return;
            }
        }
    } while (sign1 < sign2);
    
}
int main(void) { 
    int i, j;

    cin >> a1 >> b1 >> a2 >> b2;
   
    for (i = 0; i < 12; i++)
        for (j = 0; j < 12; j++)
            cin >> a[i][j];
    solution();
}

/*
1 1 1 1 1 1 1 1 1 1 1 1 
1 0 0 0 0 0 0 1 0 1 1 1 
1 0 1 0 1 1 0 0 0 0 0 1 
1 0 1 0 1 1 0 1 1 1 0 1 
1 0 1 0 0 0 0 0 1 0 0 1 
1 0 1 1 1 1 1 1 1 1 1 1 
1 0 0 0 1 0 1 0 0 0 0 1 
1 0 1 1 1 0 0 0 1 1 1 1 
1 0 0 0 0 0 1 0 0 0 0 1 
1 1 1 0 1 1 1 1 0 1 0 1 
1 1 1 1 1 1 1 0 0 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1
*/


