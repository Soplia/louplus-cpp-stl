//#include <iostream>
//#include "xmap.h"
//
//int main() {
//	jrxstl::map<std::string, int> map;                            //定义一个map
//	map.insert(jrxstl::pair<std::string, int>("zhangsan", 110));    //插入
//	map.insert(jrxstl::pair<std::string, int>("lisi", 120));
//	map.insert(jrxstl::pair<std::string, int>("wangwu", 130));
//	map.insert(jrxstl::pair<std::string, int>("mazi", 140));
//	const jrxstl::pair<const std::string, int> value(std::string("pangdun"), 150);//定义一个pair
//	map.insert(value);
//
//	std::cout << "after insert: " << std::endl;
//	auto iter = map.begin();
//	for (; iter != map.end(); ++iter)
//		std::cout << "name: " << iter->first << ' ' << "id: " << iter->second << std::endl;  //打印键值和数值
//	std::cout << "can we find lisi?: ";
//	iter = map.find(std::string("lisi"));                //查找
//	if (iter == map.end())                                 //判断是否存在
//		std::cout << "no!" << std::endl;
//	else
//		std::cout << "yes!" << std::endl;
//	std::cout << "his id is " << iter->second << std::endl;    //如果存在打印数值
//	std::cout << std::endl;
//
//	std::cout << "after erase lisi" << std::endl;
//	map.erase(iter);                                    //删除
//	iter = map.begin();
//	for (; iter != map.end(); ++iter)
//		std::cout << "name: " << iter->first << ' ' << "id: " << iter->second << std::endl;
//	system("pause");
//	return 0;
//}