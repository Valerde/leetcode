#include<bits/stdc++.h>
using namespace std;
/*
�ַ��� originalText ʹ�� б��λ���� ������ �����̶� Ϊ rows �ľ����������ܵõ�һ���ַ��� encodedText ��

originalText �Ȱ������ϵ����µķ�ʽ���õ������С�


�������ɫ��Ԫ�񣬽����Ǻ�ɫ��Ԫ��Ȼ���ǻ�ɫ��Ԫ���Դ����ƣ�ֱ������ originalText ĩβ����ͷָʾ˳��Ϊ��Ԫ�����˳�����пյ�Ԫ���� ' ' ������䡣��������������㣺�� originalText ���֮�����Ҳ��� ��Ϊ�� ��

���Ű��н��ַ����ӵ������У�����?encodedText ��


�Ȱ���ɫ��Ԫ���е��ַ����ӵ� encodedText �У������Ǻ�ɫ��Ԫ������ǻ�ɫ��Ԫ�񡣼�ͷָʾ��Ԫ�����˳��

���磬��� originalText = "cipher" �� rows = 3 ����ô���ǿ��԰���������������룺


��ɫ��ͷ��ʶ originalText ����η�������еģ���ɫ��ͷ��ʶ�γ� encodedText ��˳�������������У�encodedText = "ch? ?ie? ?pr" ��

����������ַ��� encodedText �;�������� rows ������Դ�ַ��� originalText ��

ע�⣺originalText �� ���κ�β��ո� ' ' �����ɵĲ����������� ������һ�� ���ܵ� originalText ��


*/

string decodeCiphertext(string encodedText, int rows) {
	string dt;
	int cols = encodedText.size()/rows;
	int j = 0;
	for(int k = 0; k<cols; k++) {
		for(int i = 0; i<rows; i++) {
			if(j<cols)
				dt+=(encodedText[i*cols+i+j]);

		}
		j++;
	}
	//cout<<dt<<"|";
	string res;
	int qq ;
	for(qq = dt.size()-1; qq>0 ; qq--) {
		if(dt[qq] >='a'&&dt[qq]<='z') {
			break;
		}
	}
	for(int i = 0; i<=qq; i++)
		res+=dt[i];
	return res;
}
string temp_decodeCiphertext(string encodedText, int rows) {
	int cols = encodedText.size() / rows;   // �������������
	string res;   // ���������ַ�
	for (int i = 0; i < cols; ++i) {
		// ��������ö��ÿһ��·��
		int r = 0;
		int c = i;
		while (r < rows && c < cols) {
			res.push_back(encodedText[r*cols+c]);
			++r;
			++c;
		}
	}
	// ɾȥĩβ�ո�
	while (res.size() and res.back() == ' ') {
		res.pop_back();
	}
	return res;

}

int main() {
	cout<<decodeCiphertext("iveo    eed   l te   olc",4)<<"|";
}
