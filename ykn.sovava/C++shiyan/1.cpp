#include <iostream>
#include <string>
using namespace std;

class CCat {
private:
    string name;
    int age;
    string color;
    int wea;
    string xin;
public:
    CCat() {
        name = "";
        age = 0;;
        color = "";
        wea = 0;
        xin = "";
    }
    CCat(string a, int b, string c, int d, string e) :name(a), age(b), color(c), wea(d), xin(e) {}
    void show() {
        std::cout << name << "," << age << "," << color << "," << wea << "," << xin;
    }
};

int main()
{
    int mode = 0;
    string name, color, mood;
    int age, weight;
    int c = 0;

    do
    {
        c++;
        cin >> mode;
        if (mode == 9) break;


        cin >> name >> age >> color >> weight >> mood;


        if (mode == 0)
        {
            CCat cat0;
            cat0.show();
        }
        else
        {
            CCat cat1(name, age, color, weight, mood);
            cat1.show();
        }
        cout << endl;


    } while (1);
}