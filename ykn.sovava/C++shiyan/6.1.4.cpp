#include <iostream>
using namespace std;
class Base1
{
public:
	Base1()
	{
		cout << "class Base1!" << endl;
	}
};

class Base2
{
public:
	Base2()
	{
		cout << "class Base2!" << endl;
	}
};

class Level1 :public Base2, virtual public Base1
{
public:
	Level1()
	{
		cout << "class Level1!" << endl;
	}
};
class Level2 : public Base2, virtual public Base1
{
public:
	Level2()
	{
		cout << "class Level2!" << endl;
	}
};
class TopLevel :public Level1 ,virtual public Level2
{
public:
	TopLevel()
	{
		cout << "class TopLevel!" << endl;
	}
};
int main()
{
	TopLevel obj;
	return 0;
}