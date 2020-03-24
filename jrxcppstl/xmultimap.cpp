//#include <iostream>
//#include "xmultimap.h"
//
//int main() {
//	jrxstl::multimap<std::string, int> mtmap;                    //定义一个multimap
//	mtmap.insert(jrxstl::pair<std::string, int>("zhangsan", 110));    //插入键值和数值
//	mtmap.insert(jrxstl::pair<std::string, int>("lisi", 120));
//	mtmap.insert(jrxstl::pair<std::string, int>("wangwu", 130));
//	mtmap.insert(jrxstl::pair<std::string, int>("mazi", 140));
//	const jrxstl::pair<const std::string, int> value(std::string("zhangsan"), 150);//定义一个pair
//	mtmap.insert(value);                                        //插入pair
//
//	std::cout << "After insert: " << std::endl;
//	auto iter = mtmap.begin();
//	for (; iter != mtmap.end(); ++iter)
//		std::cout << "name: " << iter->first << ' ' << "id: " << iter->second << std::endl;  //打印map
//	std::cout << "Can we find lisi?: ";
//	iter = mtmap.find(std::string("lisi"));                        //查找
//	if (iter == mtmap.end())                                     //判断是否存在
//		std::cout << "NO!" << std::endl;
//	else
//		std::cout << "YES!" << std::endl;
//	std::cout << "His id is " << iter->second << std::endl;            //如果存在打印数值
//	std::cout << std::endl;
//
//	std::cout << "After erase lisi" << std::endl;
//	mtmap.erase(iter);                                            //删除
//	iter = mtmap.begin();
//	for (; iter != mtmap.end(); ++iter)
//		std::cout << "name: " << iter->first << ' ' << "id: " << iter->second << std::endl;
//	system("pause");
//	return 0;
//}