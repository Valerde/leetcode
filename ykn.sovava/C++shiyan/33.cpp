/*
�����ǵ��ճ������У��в�ͬ�ļ����豸��ʼǱ���̨ʽ���ȣ����ǵļ���������ͬ��
1.    ����һ��ComputeDevice����Ϊ���࣬�û���ֻ��һ���麯��computing_power���������������豸���������Ӹû���������Laptop��Server�����ࣻ
2.    ����Laptop�࣬������num_cpu��int���͵����ԣ���ʾcpu�ĸ���������Ĭ�ϵĹ��캯���⣬Laptop�໹�д������Ĺ��캯����������ɶ�num_cpu���Գ�ʼ����
3.    ����Laptop�࣬ÿ��cpu������Ϊ1.25������ͨ��computing_power�������Laptop��������
4.    ����Server�࣬������num_cpu��num_gpu�������ԣ���ʾ��cpu��gpu�ĸ�����
      ����Server�࣬ÿ��CPU������Ϊ3.25�� ÿ��GPU������Ϊ5.55������ͨ��computing_power���Server��������
5.    ��Server��������'+'�������ʹ������Server�Ķ����ܹ�ֱ����ӣ��ڸ�����������server�����cpu����gpu���ֱ���ӣ�
6.    ����'<<'�������ʹ��Server������Ϣ�ܹ�����ָ���ĸ�ʽ����������ʽΪΪ��cpu����gpu����������������(1,1,8.8)
7.    ����'>>'�������ʹ���ܹ�ֱ��ͨ��cin����Server�������Ϣ��

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
* ����main����֮ǰ����д��Ĵ���
*/

/// �����main���������㲻��Ҫ�Ķ���Ҳ�������޸ģ�һ���Ķ�������0�֡���



int main() {
    int mode = -1; //���ڱ�ʾ�ǲ���Laptop�໹��Server�ࣻ
    ComputingDevice* pcd = nullptr;

    while (cin >> mode) {

        if (1 != mode && 2 != mode) break;
        if (1 == mode) { //��ʾ����Laptop��

            float ncpu1, ncpu2, ncpu3;
            cin >> ncpu1 >> ncpu2 >> ncpu3;
            Laptop l1(ncpu1), l2(ncpu2), l3(ncpu3);
            cout << setprecision(4) << l1.computing_power() << ','
                << l2.computing_power() << ',' << l3.computing_power() << endl;
            pcd = &l3; //�������豸��������Ϣ

        }
        else {
            //��ʾ����Server��
            Server s1, s2, s3;
            cin >> s1 >> s2; //����s1��s2��cpu��gpu��
            cout << s1 << " " << s2 << endl; //���s1��s2����ϸ��Ϣ
            s3 = s1 + s2; // s1��s2���
            cout << s3 << endl;
            pcd = &s3;
        }
        cout << pcd->computing_power() << endl;
    }

    return 0;
}
