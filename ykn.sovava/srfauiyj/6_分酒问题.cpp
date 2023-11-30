#include<iostream>
#include<queue>
#include<stdio.h>
#include<vector>
using namespace std;
int captain[] = { 8,5,3 };//容器标准容量
int des[3];
int cou = 0;
int step = 0;
struct state {
    int now[3];//现在各杯中酒量;
    int xulie;//在数组中位置
    int qiandao;//实现这一步骤的前一步骤，前导
};
queue<state> q;//广度优先搜索队列
vector<state> p;//顺序数组
//判断是否可以进一步进行倒酒动作,i向j里面倒酒。 
bool check(int now[], int i, int j) {
    if (now[i] == 0 || now[j] == captain[j])
        return false;
    return true;
}
//输出函数
void out(int a) {
    step += 1;
    if (p[a].xulie == 0) {
        cout << p[a].now[0] << " " << p[a].now[1] << " " << p[a].now[2] << endl;
        return;
    }
    out(p[a].qiandao);
    cout << p[a].now[0] << " " << p[a].now[1] << " " << p[a].now[2] << endl;
}
//广度优先遍历，可以求得最优解
void bfs(state s) {
    state tmp, tempr;
    s.xulie = 0;
    s.qiandao = 0;
    p.push_back(s);
    q.push(s);
    while (!q.empty()) {
        bool flag = true;
        tmp = q.front();
        for (int i = 0; i < 3; i++) {
            if (tmp.now[i] != des[i])
                flag = false;
        }
        if (flag){
            cout << "倒酒步骤为：" << endl;
            out(tmp.xulie);
            cout << "共用" << step-1 << "步" << endl;
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (tmp.now[i] > 0) {
                for (int j = 0; j < 3; j++) {
                    if (i != j && check(tmp.now, i, j)) {
                        int tmpi = tmp.now[i], tmpj = tmp.now[j];
                        tempr = tmp;
                        //daojiu
                        tmpj += tmp.now[i];
                        tmpi -= tmp.now[i];
                        //panduan
                        if (tmpi == 0 && tmpj == captain[j]) {//ikong,
                            tempr.now[i] = tmpi;
                            tempr.now[j] = tmpj;
                            cou++;
                            tempr.xulie = cou;
                            tempr.qiandao =  tmp.xulie; 
                            p.push_back(tempr);
                            q.push(tempr);
                        }
                        else if (tmpi == 0 && tmpj < captain[j]) {
                            tempr.now[i] = tmpi;
                            tempr.now[j] = tmpj;
                            cou++;
                            tempr.xulie = cou;
                            tempr.qiandao = tmp.xulie;
                            p.push_back(tempr);
                            q.push(tempr);
                        }
                        //ibukong
                        tmpi = tmp.now[i], tmpj = tmp.now[j];
                        tmpi -= (captain[j] - tmpj);
                        tmpj = captain[j];
                        if (tmpi > 0 && tmpi < captain[i]) {
                            tempr.now[i] = tmpi;
                            tempr.now[j] = tmpj;
                            cou++;
                            tempr.xulie = cou;
                            tempr.qiandao = tmp.xulie;
                            p.push_back(tempr);
                            q.push(tempr);
                        }
                    }
                }
            }
        }
        q.pop();
    }
}




int main() {
    state s;
    for (int i = 0; i < 3; i++) {
        cin >> des[i];
    }
    s.now[0] = 8;
    s.now[1] = 0;
    s.now[2] = 0;
    s.xulie = 0;
    s.qiandao = 0;
    bfs(s);
    return 0;
}

