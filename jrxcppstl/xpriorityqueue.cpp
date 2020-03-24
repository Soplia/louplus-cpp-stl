//#include <iostream>
//#include "xqueue.h"
//
//void print(jrxstl::priority_queue<int> temp) {    //打印
//	while (!temp.empty()) {
//		std::cout << temp.top() << " ";
//		temp.pop();
//	}
//	std::cout << std::endl;
//}
//
//int main() {
//	jrxstl::priority_queue<int> stc;                //定义一个优先队列
//	stc.push(3);
//	stc.push(4);
//	stc.push(2);
//	stc.push(5);
//	stc.push(7);
//	std::cout << "After push: ";
//	print(stc);
//
//	std::cout << "The size of priority_queue: " << stc.size() << std::endl;
//
//	stc.pop();
//	stc.pop();
//	std::cout << "After pop: ";
//	print(stc);
//
//	std::cout << "The size of priority_queue after pop: " << stc.size() << std::endl;
//
//	std::cout << "The top of priority_queue: " << stc.top() << std::endl;
//	system("pause");
//	return 0;
//}