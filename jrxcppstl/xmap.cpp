//#include <iostream>
//#include "xmap.h"
//
//int main() {
//	jrxstl::map<std::string, int> map;                            //����һ��map
//	map.insert(jrxstl::pair<std::string, int>("zhangsan", 110));    //����
//	map.insert(jrxstl::pair<std::string, int>("lisi", 120));
//	map.insert(jrxstl::pair<std::string, int>("wangwu", 130));
//	map.insert(jrxstl::pair<std::string, int>("mazi", 140));
//	const jrxstl::pair<const std::string, int> value(std::string("pangdun"), 150);//����һ��pair
//	map.insert(value);
//
//	std::cout << "after insert: " << std::endl;
//	auto iter = map.begin();
//	for (; iter != map.end(); ++iter)
//		std::cout << "name: " << iter->first << ' ' << "id: " << iter->second << std::endl;  //��ӡ��ֵ����ֵ
//	std::cout << "can we find lisi?: ";
//	iter = map.find(std::string("lisi"));                //����
//	if (iter == map.end())                                 //�ж��Ƿ����
//		std::cout << "no!" << std::endl;
//	else
//		std::cout << "yes!" << std::endl;
//	std::cout << "his id is " << iter->second << std::endl;    //������ڴ�ӡ��ֵ
//	std::cout << std::endl;
//
//	std::cout << "after erase lisi" << std::endl;
//	map.erase(iter);                                    //ɾ��
//	iter = map.begin();
//	for (; iter != map.end(); ++iter)
//		std::cout << "name: " << iter->first << ' ' << "id: " << iter->second << std::endl;
//	system("pause");
//	return 0;
//}