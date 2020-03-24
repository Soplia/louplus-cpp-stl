/*
#include <iostream>
#include "xdeque.h"

void print(jrxstl::deque<int> temp) {
	jrxstl::deque<int>::iterator it = temp.begin();
	for (; it != temp.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main() {
	jrxstl::deque<int> val;
	val.push_back(1);
	val.push_back(4);
	val.push_back(7);
	std::cout << "After pushback:" << std::endl;
	print(val);

	val.push_front(8);
	val.push_front(5);
	val.push_front(2);
	std::cout << "After pushfront:" << std::endl;
	print(val);

	std::cout << "The size of val: " << val.size() << std::endl;

	std::cout << "After copy:" << std::endl;
	jrxstl::deque<int> val1(val);
	print(val1);

	std::cout << "After popback:" << std::endl;
	val.pop_back();
	print(val);

	std::cout << "After popfront:" << std::endl;
	val.pop_front();
	print(val);
	system("pause");

}
*/