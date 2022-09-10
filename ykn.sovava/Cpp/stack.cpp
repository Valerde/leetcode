#include <iostream>
#include <stack>
#include <list>
using namespace std;
int main()
{
    cout << "àË¿ÍÍø(www.haicoder.net)\n" << endl;
    list<int> values{ 1, 2, 3 };
    stack<int, list<int>> my_stack(values);
    cout << "size of my_stack: " << my_stack.size() << endl;
    while (!my_stack.empty())
    {  
        cout << my_stack.top() << endl;
        my_stack.pop();
    }
    return 0; 
}
