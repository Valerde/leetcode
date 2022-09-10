#include <iostream>
#include <queue>
#include <list>
using namespace std;
int main() {
	cout << "àË¿ÍÍø(www.haicoder.net)\n" << endl;
	std::deque<int> values {99, 1024, 100};
	std::queue<int> my_queue(values);
	cout << "size of my_queue: " << my_queue.size() << endl;
	while (!my_queue.empty()) {
		cout << my_queue.front() << endl;
		my_queue.pop();
	}
	return 0;
}
