/*
请定义一个抽象类CVec，并从CVec以public方式派生出类CVec2和CVec3。具体要求如下：
1)   CVec类只有一个纯虚函数float length()，目的是返回向量的长度，向量长度的计算方法是各分量的平方和再开平方，比如二维向量(x, y)，其长度的计算公式为sqrt(x* x + y * y)。
2)   CVec类没有属性
3)   CVec2类代表二维向量。它有两个公有的float类型属性_x和_y，分别存储二维向量的x和y分量值
4)   CVec2类有一个带参数的构造函数，第一个参数是x分量值，第二个参数是y分量值。其作用是对其公有属性进行初始化。
5)   CVec2类需要重新定义其继承自基类的length成员函数，实现计算二维向量的长度
6)   对运算符“ + ”进行重载，实现两个CVec2对象的求和，返回值是两个向量的和矢量，而且和矢量的长度被归一化为1。和矢量的计算方法是两个向量的对应分量之和形成的新向量。
长度被归一化为1的意思是保持向量的方向不变，将其长度变为1，即向量的每个分量都除以向量的长度。
7)   CVec3类代表三维向量。它有三个公有的float类型属性_x、_y和_z，分别存储三维向量的x, y和z分量值
8)   CVec3类有一个带参数的构造函数，第一个参数是x分量值，第二个参数是y分量值，第三个参数是z分量值。其作用是对其公有属性进行初始化。
9)   CVec3类需要重新定义其继承自基类的length成员函数，实现计算三维向量的长度
10) 对运算符“ + ”进行重载，实现两个CVec3对象的求和，返回值是两个三维向量的和矢量，而且和矢量的长度被归一化为1


请把下面的所有代码复制到你的开发环境中，按照上文要求填充所需要的代码，然后提交该代码进行测试。（注意：main函数中的内容是不能修改的，违者0分）

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
* 请在main函数之前，填写你的代码
*/


/// 下面的main函数代码你不需要阅读，也【不能修改；一旦改动，本题0分】。
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