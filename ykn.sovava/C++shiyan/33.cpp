/*
在我们的日常生活中，有不同的计算设备如笔记本，台式机等，他们的计算能力不同。
1.    定义一个ComputeDevice类作为基类，该基类只有一个虚函数computing_power，用来描述计算设备的算力。从该基类派生出Laptop和Server两个类；
2.    对于Laptop类，该类有num_cpu的int类型的属性，表示cpu的个数。除了默认的构造函数外，Laptop类还有带参数的构造函数，用于完成对num_cpu属性初始化；
3.    对于Laptop类，每个cpu的算力为1.25，可以通过computing_power函数获得Laptop的算力；
4.    对于Server类，该类有num_cpu和num_gpu两个属性，表示其cpu和gpu的个数。
      对于Server类，每个CPU的算力为3.25， 每个GPU的算力为5.55；可以通过computing_power获得Server的算力；
5.    在Server类中重载'+'运算符，使得两个Server的对象能够直接相加，在该运算中两个server对象的cpu数和gpu数分别相加；
6.    重载'<<'运算符，使得Server对象信息能够按照指定的格式输出，输出格式为为（cpu数，gpu数，算力），例如(1,1,8.8)
7.    重载'>>'运算符，使得能够直接通过cin输入Server对象的信息；

*/
#include <iostream>
#include <iomanip>
using namespace std;
class ComputingDevice {
public:
    virtual float computing_power() = 0;
};
class Laptop : public ComputingDevice {
private:
    int num_cpu;
    int suanli;
public:
    Laptop() { num_cpu = 0; }
    Laptop(int a):num_cpu(a){}
    float computing_power() { return 1.25 * num_cpu; }
};
class Server :public ComputingDevice {
private:
    int num_cpu, num_gpu;
public:
    float computing_power() { return 3.25 * num_cpu+5.55*num_gpu; }
    friend Server operator + (Server& c1, Server& c2);
    Server() { num_cpu = 0; num_gpu = 0; }
    Server(int a,int b):num_cpu(a),num_gpu(b){}
    friend ostream& operator<<(ostream& out, Server& a) {
        out << "(" << a.num_cpu << "," << a.num_gpu << "," << a.computing_power()<<")";
        return out;
    }
    friend istream& operator>>(istream& in, Server& a) {
        in >> a.num_cpu >> a.num_gpu;
        return in;
    }
};
Server operator + (Server& c1, Server& c2) {
    Server a(0, 0);
    a.num_cpu = c2.num_cpu + c1.num_cpu;
    a.num_gpu = c2.num_gpu + c1.num_gpu;
    return a;
}
/*
* 请在main函数之前，填写你的代码
*/

/// 下面的main函数代码你不需要阅读，也【不能修改；一旦改动，本题0分】。



int main() {
    int mode = -1; //用于表示是操作Laptop类还是Server类；
    ComputingDevice* pcd = nullptr;

    while (cin >> mode) {

        if (1 != mode && 2 != mode) break;
        if (1 == mode) { //表示操作Laptop类

            float ncpu1, ncpu2, ncpu3;
            cin >> ncpu1 >> ncpu2 >> ncpu3;
            Laptop l1(ncpu1), l2(ncpu2), l3(ncpu3);
            cout << setprecision(4) << l1.computing_power() << ','
                << l2.computing_power() << ',' << l3.computing_power() << endl;
            pcd = &l3; //输出多个设备的算力信息

        }
        else {
            //表示操作Server类
            Server s1, s2, s3;
            cin >> s1 >> s2; //输入s1和s2的cpu和gpu数
            cout << s1 << " " << s2 << endl; //输出s1和s2的详细信息
            s3 = s1 + s2; // s1和s2相加
            cout << s3 << endl;
            pcd = &s3;
        }
        cout << pcd->computing_power() << endl;
    }

    return 0;
}
