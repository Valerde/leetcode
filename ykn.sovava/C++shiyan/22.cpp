#include<iostream>
using namespace std;
class CMyMath {
public:
	static float GetHalfValue(float a) {
		return a / 2;
	}
	float GetMyValue() {
		return myvalue;
	}
	CMyMath() { myvalue = -1; }
	CMyMath(float a):myvalue(a){}
	CMyMath(CMyMath& a) {
		myvalue = a.myvalue + 1;
	}
private:
	float myvalue;

};

int main()
{
    
    int code = 0;
    CMyMath obj1;
    CMyMath obj2(5);
    CMyMath obj3(obj2);

    do {
        cin >> code;
        switch (code) {
        case 1:
            cout << CMyMath::GetHalfValue(float(code)) << endl;
            break;
        case 2:
            cout << obj1.GetMyValue() << endl;
            break;
        case 3:
            cout << obj2.GetMyValue() << endl;
            break;
        case 4:
            cout << obj3.GetMyValue() << endl;
            break;
        default:
            float v = CMyMath::GetHalfValue(float(code));
            CMyMath* pObj = new CMyMath(v);
            CMyMath* pObj1 = new CMyMath(*pObj);
            cout << v << "/" << pObj1->GetMyValue() << "/" << pObj->GetMyValue() << endl;
            delete pObj;
            delete pObj1;
            break;
        }
    } while (code > 0);

    return 0;
}