#include <iostream>
using namespace std;

class Clock
{
public:                     //ע��ӹ��г�Ա˽�г�Ա���������ӳ���İ�ȫ��
    void set_clock();
    void show_clock();
private:
    int hour;
    int minute;
    int second;
};
                                    //�������ں�������main����ǰ��
void Clock::set_clock()             //��������ֵΪvoid���Ҷ������ں�����ʱ��Ҫ������
{
    cin >> hour;                    //���ں�������Ҫʹ��t.hour�ı�����ֱ����hour����
    cin >> minute;
    cin >> second;
}
void Clock::show_clock()                //�κ�����������һ��������
{
    cout << hour << ":" << minute << ":" << second << endl;
}

int main()
{
    Clock clock;                        //��main�������Ե�ʱ��Ҫ�Ƚ���һ����
    clock.set_clock();                  //�����ຯ����ʱ��Ҫ��ǰ��Ӷ�����
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