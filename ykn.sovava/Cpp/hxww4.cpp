#include<bits/stdc++.h>
using namespace std;


int main() {
    string str1, str2;
    cin >> str1 >> str2;

    string temp = str1 + str2;
    str1 = "", str2 = "";
    for (int i = 0; i < temp.size(); i++) {
        i % 2 == 0 ? str1 += temp[i] : str2 += temp[i];
    }
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    temp = "";
    for (int i = 0; i < min(str1.size(), str2.size()); i++) {
        temp += str1[i];
        temp += str2[i];
    }
    if (str1.size() != str2.size())temp += str1.size() > str2.size() ?
                                               str1[str1.size() - 1] : str2[str2.size() - 1];

    unordered_map<char, char> m;
    m.emplace('1', '8');
    m.emplace('2', '4');
    m.emplace('3', 'C');
    m.emplace('4', '2');
    m.emplace('5', 'A');
    m.emplace('6', '6');
    m.emplace('7', 'E');
    m.emplace('8', '1');
    m.emplace('9', '9');
    m.emplace('a', '5');
    m.emplace('A', '5');
    m.emplace('b', 'D');
    m.emplace('B', 'D');
    m.emplace('c', '3');
    m.emplace('d', 'B');
    m.emplace('e', '7');
    m.emplace('f', 'F');
    m.emplace('C', '3');
    m.emplace('D', 'B');
    m.emplace('E', '7');
    m.emplace('F', 'F');
    string res;
    for (int i = 0; i < temp.size(); i++) {
       if(m.find(temp[i])!=m.end()) res += m[temp[i]];
       else res+=temp[i];
    }
    cout << res << endl;
}
