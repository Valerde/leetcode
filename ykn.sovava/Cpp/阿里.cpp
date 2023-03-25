//#include <stdio.h>

#include<bits/stdc++.h>
using namespace std;
struct st{
    int *p;
    int i;
    char a;
};
int sz = sizeof(struct st);
int main() {
    char *a[] = {"work", "at", "alibaba"};
    char **pa = a;
    pa++;
    printf("%s\n", *pa);
    printf("%d", sz);
    
    
    vector<int>array;
    array.push_back(100);
    array.push_back(300);
    array.push_back(300);
    array.push_back(300);
    array.push_back(300);
    array.push_back(500);
    vector<int>::iterator itor;
    for(itor=array.begin();itor!=array.end();itor++)
    {
        if(*itor==300)
        {
            itor=array.erase(itor);
        }
    }
    for(itor=array.begin();itor!=array.end();itor++)
    {
            cout<<*itor<<"";
    }
}

