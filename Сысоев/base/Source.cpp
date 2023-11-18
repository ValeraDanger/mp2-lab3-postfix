#include "stack.h"

void main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	Stack<int> st(&(arr[0]), 5);
	for (size_t i = 0; i < 5; i++) {
		std::cout << st.top() << std::endl;
		st.pop();
	}
}