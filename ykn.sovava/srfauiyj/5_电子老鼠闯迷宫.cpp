#include<iostream>
#include<cstdio>
using namespace std;
const int mov[4][2] = { {0,1 }, {0, -1},{ -1, 0},{ 1, 0} };
int size = 12;
int a[12][12];//����״��
int save[12 * 12][2];//[��ǰ�Ѿ��������ĵ�����][�������꡿
int path[12 * 12];//����Ϊ��ǰ������š��洢������Ϊ��һ���
int a1, b1;//����������
int a2, b2;//�յ�����
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
    int sign1=0, sign2=1;//sign1Ϊ�մ�����������ţ�sign2Ϊ��ȷ·�����path[]
    path[sign2] = sign1;//��һ��������ǰ���϶�Ϊ������
    save[1][0] = a1; save[1][1] = b1;
    a[a1][b1] = 1;//������϶���������Ϊ1
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
                cout << "����Ϊ" << countlen;
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


