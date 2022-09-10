#include <iostream>
#include <vector>
using namespace std;
int main()
{

    vector<string> vec{"Hello", "World", "HaiCoder", "haicoder.net", "www.haicoder.net"};
    cout << "vec1 = " << vec[0] << endl;
    cout << "vec2 = " << vec.at(1) << endl;
    cout << "vec3 = " << *(vec.data()+2) << endl;
    cout << "vec4 = " <<vec.front()<<endl;
    cout << "vec5 = " << vec.back() << endl;
    return 0; 
}
