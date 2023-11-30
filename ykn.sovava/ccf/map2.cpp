#include <iostream>
#include <map>
using namespace std;
int main()
{
    cout << "àË¿ÍÍø(www.haicoder.net)\n" << endl;
	map<string, string> map1;
 	map1.emplace("Shell","https://haicoder.net/shell/shell-tutorial.html");
    map1.emplace("Linux", "https://haicoder.net/linux/linux-tutorial.html");
    map1.insert({"Golang", "https://haicoder.net/golang/golang-tutorial.html"});
	for (auto i = map1.begin(); i != map1.end(); i++) 
	{
        cout << i->first << " " << i->second << endl;
    }
    return 0; 
}
