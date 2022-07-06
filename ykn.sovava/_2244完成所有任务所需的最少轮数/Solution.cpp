#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//执行用时：160 ms, 在所有 C++ 提交中击败了81.59%的用户
//内存消耗：92.4 MB, 在所有 C++ 提交中击败了99.29%的用户
    int minimumRounds(vector<int>& tasks) {
        int len = tasks.size();
        if (len < 2) {
            return -1;
        }
        sort(tasks.begin(),tasks.end());
        int temp = tasks[0];
        int count = 0;
        int tempCount = 0;
        bool flag = 0;//flag用来标记当前任务难度级别有没有3个的,如果有三个的,就可以把3+1转化为2+2
        for (int i = 0; i < len; i++) {
            if (temp != tasks[i]) {//跳转下一个
                temp = tasks[i];//记录当前所在的难度组
                if (tempCount == 2) {
                    count++;
                    tempCount = 0;
                } else if (tempCount == 1) {
                    if (!flag)
                        return -1;
                    else {//flag用来标记当前任务难度级别有没有3个的,如果有三个的,就可以把3+1转化为2+2
                        count++;
                        tempCount = 0;
                    }
                }
                tempCount++;
                flag = 0;
            } else {//当前难度组计数
                tempCount++;
                if (tempCount == 3) {
                    count++;
                    tempCount = 0;
                    flag = 1;
                }
            }
        }
        if (tempCount == 1) {
            if (!flag)
                return -1;
            else
                count++;

        } else if (tempCount == 2) {
            count++;
        }

        return count;
    }

    int main(){
    	vector<int> tasks =  {2, 2, 2, 3, 3, 4, 4, 4, 4, 4};


    	//for(int i = 0;i<10;i++){
    		//cout<<minimumRounds(tasks);
    	//}
    	return 0;
    }
