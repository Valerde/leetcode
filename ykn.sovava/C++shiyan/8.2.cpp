/*
已知数据文件IN.DAT中存有20个整数，每个整数间用空格分隔。有一类Array的结构如下：
class Array{
     int A[20];
public:
     Array(){
        for(int i=0;i<20;i++)  A[i]=0;
     }
int getNumberA(Array  &a,int k){return a.A[k];}
     void getdata();//读数据函数
     void max_min(int &,int &);//排序函数
     void putdata(int &,int &);//写结果数据函数
};
其中：
成员函数getdata()的功能为：从数据文件IN.DAT中把20个数据读出来存入数据成员A[]中。
成员函数max_min(int &,int &)的功能为：求数据成员A[]中20个整数的最大值和最小值。
成员函数putdata(int &,int &)的功能为：把求得的数据成员A[]中20个整数的最大值和最小值输出到数据文件OUT.DAT。
要求：在类外写出上述三个成员函数的实现代码，并在main函数中对该类进行测试。
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
    void getdata();//读数据函数
    void max_min(int&, int&);//排序函数
    void putdata(int&, int&);//写结果数据函数
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