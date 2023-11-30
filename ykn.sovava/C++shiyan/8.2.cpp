/*
��֪�����ļ�IN.DAT�д���20��������ÿ���������ÿո�ָ�����һ��Array�Ľṹ���£�
class Array{
     int A[20];
public:
     Array(){
        for(int i=0;i<20;i++)  A[i]=0;
     }
int getNumberA(Array  &a,int k){return a.A[k];}
     void getdata();//�����ݺ���
     void max_min(int &,int &);//������
     void putdata(int &,int &);//д������ݺ���
};
���У�
��Ա����getdata()�Ĺ���Ϊ���������ļ�IN.DAT�а�20�����ݶ������������ݳ�ԱA[]�С�
��Ա����max_min(int &,int &)�Ĺ���Ϊ�������ݳ�ԱA[]��20�����������ֵ����Сֵ��
��Ա����putdata(int &,int &)�Ĺ���Ϊ������õ����ݳ�ԱA[]��20�����������ֵ����Сֵ����������ļ�OUT.DAT��
Ҫ��������д������������Ա������ʵ�ִ��룬����main�����жԸ�����в��ԡ�
*/

#include<iostream>
#include<fstream>
using namespace std;
class Array {
    int A[20];
public:
    Array() {
        for (int i = 0; i < 20; i++)  A[i] = 0;
    }
    int getNumberA(Array& a, int k) { return a.A[k]; }
    void getdata();//�����ݺ���
    void max_min(int&, int&);//������
    void putdata(int&, int&);//д������ݺ���
};
void Array::getdata(){
    ifstream in("in.dat", ios::in | ios::binary);
    if (!in) {
        cout << "open error!" << endl;
        abort();
    }
    int k,i=0;
    while (in >> k)
        A[i++] = k;
    in.close();
}
void Array::max_min(int& a, int& b){
    a = b = A[0];//a:max;;;b:min
    for (int i = 0; i < 20; i++) {
        if (a < A[i]) {
            a = A[i];
        }
        if (b > A[i]) {
            b = A[i];
        }
    }
}
void Array::putdata(int& a, int& b) {
    ofstream out("out.dat", ios::out);
    out << a << endl;
    out<<b<<endl;
    out.close();
}
int main(void) {
    Array a;
    a.getdata();
    int max, min;
    a.max_min(max, min);
    a.putdata(max, min);

    for(int i=0;i<20;i++)
        cout << a.getNumberA(a,i) << endl;
    return 0;
}