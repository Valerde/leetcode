#include <iostream>
using namespace std;
class test
{
public:
    test();
    int getint() { return num; }
    float getfloat() { return fl; }
    ~test();
private:
    int num;
    float fl;
};
test::test()
{
    cout << "Initalizing default" << endl;
    num = 0;
    fl = 0.0;
}
test::~test()
{
    cout << "Destructor is active" << endl;
}
int main()
{
    test array[2];
    cout << array[1].getint() << "  " << array[1].getfloat() << endl;
    return 0;
}