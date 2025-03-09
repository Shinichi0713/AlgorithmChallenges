#include <stack>
#include <stdio.h>

using namespace std;

int que_executing() {
	stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);

	printf("%d\n", stack.top());
	stack.pop();


	return 100;
}
