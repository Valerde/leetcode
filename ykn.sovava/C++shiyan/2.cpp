/*
�붨��һ��������CVec������CVec��public��ʽ��������CVec2��CVec3������Ҫ�����£�
1)   CVec��ֻ��һ�����麯��float length()��Ŀ���Ƿ��������ĳ��ȣ��������ȵļ��㷽���Ǹ�������ƽ�����ٿ�ƽ���������ά����(x, y)���䳤�ȵļ��㹫ʽΪsqrt(x* x + y * y)��
2)   CVec��û������
3)   CVec2������ά�����������������е�float��������_x��_y���ֱ�洢��ά������x��y����ֵ
4)   CVec2����һ���������Ĺ��캯������һ��������x����ֵ���ڶ���������y����ֵ���������Ƕ��乫�����Խ��г�ʼ����
5)   CVec2����Ҫ���¶�����̳��Ի����length��Ա������ʵ�ּ����ά�����ĳ���
6)   ��������� + ���������أ�ʵ������CVec2�������ͣ�����ֵ�����������ĺ�ʸ�������Һ�ʸ���ĳ��ȱ���һ��Ϊ1����ʸ���ļ��㷽�������������Ķ�Ӧ����֮���γɵ���������
���ȱ���һ��Ϊ1����˼�Ǳ��������ķ��򲻱䣬���䳤�ȱ�Ϊ1����������ÿ�����������������ĳ��ȡ�
7)   CVec3�������ά�����������������е�float��������_x��_y��_z���ֱ�洢��ά������x, y��z����ֵ
8)   CVec3����һ���������Ĺ��캯������һ��������x����ֵ���ڶ���������y����ֵ��������������z����ֵ���������Ƕ��乫�����Խ��г�ʼ����
9)   CVec3����Ҫ���¶�����̳��Ի����length��Ա������ʵ�ּ�����ά�����ĳ���
10) ��������� + ���������أ�ʵ������CVec3�������ͣ�����ֵ��������ά�����ĺ�ʸ�������Һ�ʸ���ĳ��ȱ���һ��Ϊ1


�����������д��븴�Ƶ���Ŀ��������У���������Ҫ���������Ҫ�Ĵ��룬Ȼ���ύ�ô�����в��ԡ���ע�⣺main�����е������ǲ����޸ĵģ�Υ��0�֣�

*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class CVec {
public:
    virtual float length() = 0;
};
class CVec2 :public CVec {
public:
    float _x, _y;
    CVec2(float x, float y) :_x(x), _y(y) {}
    float length() { return sqrt(_x * _x + _y * _y); }
    friend CVec2 operator + (CVec2& c1, CVec2& c2);

};
class CVec3 :public CVec {
public:
    float _x, _y, _z;
    CVec3(float x, float y, float z) :_x(x), _y(y), _z(z) {}
    float length() { return sqrt(_x * _x + _y * _y + _z * _z); }
    friend CVec3 operator + (CVec3& c1, CVec3& c2);
};
CVec2 operator + (CVec2& c1, CVec2& c2) {
    CVec2 a(0, 0);
    a._x = c2._x + c1._x;
    a._y = c2._y + c1._y;
    float len = a.length();
    a._x /= len;
    a._y /= len;
    return a;
}
CVec3 operator + (CVec3& c1, CVec3& c2) {
    CVec3 a(0, 0, 0);
    a._x = c2._x + c1._x;
    a._y = c2._y + c1._y;
    a._z = c1._z + c2._z;
    float len = a.length();
    a._x /= len;
    a._y /= len;
    a._z /= len;
    return a;
}
/*
* ����main����֮ǰ����д��Ĵ���
*/


/// �����main���������㲻��Ҫ�Ķ���Ҳ�������޸ģ�һ���Ķ�������0�֡���
int main()
{
    int mode = -1;
    CVec* pV = NULL;


    do
    {
        std::cin >> mode;
        if (mode != 2 && mode != 3) break;


        float v1_x, v1_y, v1_z, v2_x, v2_y, v2_z;
        if (mode == 2)
            std::cin >> v1_x >> v1_y >> v2_x >> v2_y;
        else
            std::cin >> v1_x >> v1_y >> v1_z >> v2_x >> v2_y >> v2_z;


        if (mode == 2)
        {
            CVec2 v2d1(v1_x, v1_y), v2d2(v2_x, v2_y), v2d_sum(0, 0);


            cout << setprecision(4) << v2d1.length() << "," << v2d2.length() << endl;


            v2d_sum = v2d1 + v2d2;
            cout << setprecision(4) << v2d_sum._x << "," << v2d_sum._y << endl;


            pV = &v2d1;
        }
        else
        {
            CVec3 v3d1(v1_x, v1_y, v1_z), v3d2(v2_x, v2_y, v2_z), v3d_sum(0, 0, 0);


            cout << setprecision(4) << v3d1.length() << "," << v3d2.length() << endl;


            v3d_sum = v3d1 + v3d2;
            cout << setprecision(4) << v3d_sum._x << "," << v3d_sum._y << "," << v3d_sum._z << endl;


            pV = &v3d1;
        }


        cout << setprecision(4) << pV->length() << endl;


    } while (true);


    return 0;
}