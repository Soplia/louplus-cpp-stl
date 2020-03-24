#include <iostream>
#include "xmultiset.h"

int main() {
	jrxstl::multiset<int> imultiset;                        //定义一个multiset
	imultiset.insert(1);                                //插入5个值
	imultiset.insert(2);
	imultiset.insert(1);
	imultiset.insert(4);
	imultiset.insert(4);
	std::cout << "After insert ";

	auto it = imultiset.begin();
	for (; it != imultiset.end(); it++)                    //输出
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "size:" << imultiset.size() << std::endl;    //返回元素个数
	std::cout << "lower_bound 2: " << *imultiset.lower_bound(2) << std::endl;                                            //找到第一个小于等于2的数
	std::cout << "upper_bound 2: " << *imultiset.upper_bound(2) << std::endl;                                            //找到第一个大于2的数
	it = imultiset.find(2);                                //查找
	std::cout << "Can we find 2?: ";
	if (it == imultiset.end())
		std::cout << "NO!" << std::endl;
	else
		std::cout << "YES!" << std::endl;

	std::cout << "After eraase 2" << std::endl;
	imultiset.erase(2);                                    //删除
	it = imultiset.find(2);
	std::cout << "Can we find 2?: ";
	if (it == imultiset.end())
		std::cout << "NO!" << std::endl;
	else
		std::cout << "YES!" << std::endl;
	std::cout << std::endl;
	system("pause");
	return 0;
}