#include <iostream>
using namespace std;

class Clock
{
public:                     //注意加共有成员私有成员，可以增加程序的安全性
    void set_clock();
    void show_clock();
private:
    int hour;
    int minute;
    int second;
};
                                    //两个类内函数放在main函数前面
void Clock::set_clock()             //函数返回值为void，且定义类内函数的时候要加类名
{
    cin >> hour;                    //类内函数不需要使用t.hour的变量，直接用hour即可
    cin >> minute;
    cin >> second;
}
void Clock::show_clock()                //次函数错误与上一函数类似
{
    cout << hour << ":" << minute << ":" << second << endl;
}

int main()
{
    Clock clock;                        //在main函数测试的时候要先建立一个类
    clock.set_clock();                  //调用类函数的时候要在前面加对象名
    clock.show_clock();
}

/*
#include <iostream>
    using namespace std;
    class Clock
    {   void set_clock(void);
    void show_clock(void);
        int hour;
    int minute;
    int second;
};
Clock clock;
    int main()
{
    set_clock();
   show_clock ();
     }
int set_clock(void)
{
    cin>>t.hour;
    cin>>t.month;
    cin>>t.second;
}
    int show_clock(void)
{
cout<<t.hour<<":"<<t.minute<<":"<<t.second<<endl;
  }
*/