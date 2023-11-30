#include <iostream>
using namespace std;
class Salary{
public:
    Salary();
    Salary(double w,double s,double r,double wa,double e):Wage(w),Subsidy(s),Rent(r),WaterFee(wa),ElecFee(e){}
    void setWage(double f) { Wage = f; }
    double getWage() { return Wage; }
    void setSubsidy(double f) { Subsidy = f; }
    double getSubsidy() { return Subsidy; }
    void setRent(double f) { Rent = f; }
    double getRent() { return Rent; }
    void setWaterFee(double f) { WaterFee = f; }
    double getWaterFee() { return WaterFee; }
    void setElecFee(double f) { ElecFee = f; }
    double getElecFee() { return ElecFee; }
    double RealSalary() { return Wage + Subsidy - Rent - WaterFee - ElecFee; }//计算实发工资
private:
    double Wage;
    double Subsidy;
    double Rent;
    double WaterFee;
    double ElecFee;
};
Salary::Salary() {
    Wage = Subsidy = Rent = WaterFee = ElecFee = 0;
}
int main(void) {
    Salary person(15.3,462.3,15,46.2,45.1);
    double f;
    cout <<"wage is " << person.getWage() << endl<<"set Wage:";
    cin >> f;
    person.setWage(f);
    cout << "wage is " << person.getWage() << endl;
    cout << "subsidy is " << person.getSubsidy() << endl<<"set subsidy:";
    cin >> f;
    person.setSubsidy(f);
    cout << "subsidy is " << person.getSubsidy() << endl;
    cout << "Rent is " << person.getRent() << endl << "set rent:";
    cin >> f;
    person.setRent(f);
    cout << "Rent is " << person.getRent() << endl;
    cout << "WaterFee is " << person.getWaterFee() << endl << "set WaterFee:";
    cin >> f;
    person.setWaterFee(f);
    cout << "WaterFee is " << person.getWaterFee() << endl;
    cout << "ElecFee is " << person.getElecFee() << endl << "set ElecFee:";
    cin >> f;
    person.setElecFee(f);
    cout << "ElecFee is " << person.getElecFee() << endl;
    cout << "salary is:" << person.RealSalary()<<endl;
    return 0;
}