//#include <iostream>
//#include "xset.h"
//
//int main() {
//	int i;
//	int arr[6] = { 4,2,7,1,9,8 };                    //定义一个数组
//	std::cout << "Before putting in set: ";
//	for (int i = 0; i < 6; i++)
//		std::cout << arr[i] << " ";                    //给数组赋值
//	std::cout << std::endl;
//
//	jrxstl::set<int> iset(arr, arr + 6);            //创建一个set容器
//	std::cout << "lower_bound 2: " << *iset.lower_bound(2) << std::endl;//找到第一个小于等于2的数
//	std::cout << "upper_bound 2: " << *iset.upper_bound(2) << std::endl;//找到第一个大于2的数
//
//	std::cout << "After insert and put 3: ";
//	iset.insert(3);                                //插入
//	jrxstl::set<int>::iterator it;
//	for (it = iset.begin(); it != iset.end(); it++)    //打印set
//	{
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;
//	it = iset.find(8);                            //查找
//	std::cout << "Can we find 8?: ";
//	if (it == iset.end())                         //判断是否存在
//		std::cout << "NO!" << std::endl;
//	else
//		std::cout << "YES!" << std::endl;
//	std::cout << std::endl;
//	system("pause");
//	return 0;
//}