#include<iostream>
using namespace std;
class ABC {
	int a, b, c;
public:
	ABC(int x, int y, int z) :a(x), b(y), c(z) {}
	friend ostream& operator<<(ostream& out, ABC& f);
};
ostream& operator<<(ostream& out, ABC& f)
{
	out << "a=" << f.a << endl << "b=" << f.b << endl << "c=" << f.c << endl;
	return out;
}
int main() {
	ABC obj(10, 20, 30);
	cout << obj;
	return 0;
}