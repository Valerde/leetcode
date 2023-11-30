#include<iostream>
using namespace std;
class intArray
{
public:
	intArray(int size);//构造函数
	intArray(const intArray& x);//复制构造函数
	~intArray();//析构函数
	bool Set(int i, int elem);//设置第i个数组元素的值，设置成功返回true，失败返回false
	bool Get(int i, int& elem); //获取第i个数组元素的值，获取成功返回true，失败返回false
	int Length() const;//获取数组的长度
	void ReSize(int size); //重置数组
	void Print();//输出数组
private:
	int* element;            //指向动态数组的指针
	int arraysize;            //数组的当前长度
};
intArray::intArray(int size) {
	arraysize = size;
	element = new int[arraysize];
	for (int i = 0; i < size; i++)
		element[i] = 0;
}
intArray::intArray(const intArray& x) {
	arraysize = x.arraysize;
	element = new int[arraysize];
	for (int i = 0; i < arraysize; i++)
	{
		element[i] = x.element[i];
	}
}
intArray::~intArray(){
	delete element;
	element = NULL;
	cout << "delete" << endl;
}
bool intArray::Set(int i,int elem) {
	element[i] = elem;
	if (element[i] == elem)
		return true;
	else
		return false;
}
bool intArray::Get(int i, int& elem) {
	elem = *(element + i);
	return true;
}
int intArray::Length()const {
	return arraysize;
}
void intArray::ReSize(int size) {
	arraysize = size;
	element = new int[size];
	for (int i = 0; i < size; i++) {
		*(element + i) = 0;
	}
}
void intArray::Print() {
	for (int i=0; i < arraysize; i++)
		cout << *(element + i) << endl;
}
int main(void) {
	intArray a(2);
	a.Print();
	cout << "-------------------" << endl;
	if (a.Set(1, 2))
		a.Print();
	cout << "---------------------" << endl;
	int elem;
	if (a.Get(1, elem))
		cout << elem << endl;
	cout << "---------------------" << endl;
	a.ReSize(3);
	a.Print();
	cout << "---------------------" << endl;
	intArray b(a);
	b.Print();
	cout << "---------------------" << endl;
	cout << "length=" << b.Length() << endl;
	return 0;
}