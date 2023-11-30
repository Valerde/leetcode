#include<iostream>
using namespace std;
class intArray
{
public:
	intArray(int size);//���캯��
	intArray(const intArray& x);//���ƹ��캯��
	~intArray();//��������
	bool Set(int i, int elem);//���õ�i������Ԫ�ص�ֵ�����óɹ�����true��ʧ�ܷ���false
	bool Get(int i, int& elem); //��ȡ��i������Ԫ�ص�ֵ����ȡ�ɹ�����true��ʧ�ܷ���false
	int Length() const;//��ȡ����ĳ���
	void ReSize(int size); //��������
	void Print();//�������
private:
	int* element;            //ָ��̬�����ָ��
	int arraysize;            //����ĵ�ǰ����
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