//#include <iostream>
//#include "xmultimap.h"
//
//int main() {
//	jrxstl::multimap<std::string, int> mtmap;                    //����һ��multimap
//	mtmap.insert(jrxstl::pair<std::string, int>("zhangsan", 110));    //�����ֵ����ֵ
//	mtmap.insert(jrxstl::pair<std::string, int>("lisi", 120));
//	mtmap.insert(jrxstl::pair<std::string, int>("wangwu", 130));
//	mtmap.insert(jrxstl::pair<std::string, int>("mazi", 140));
//	const jrxstl::pair<const std::string, int> value(std::string("zhangsan"), 150);//����һ��pair
//	mtmap.insert(value);                                        //����pair
//
//	std::cout << "After insert: " << std::endl;
//	auto iter = mtmap.begin();
//	for (; iter != mtmap.end(); ++iter)
//		std::cout << "name: " << iter->first << ' ' << "id: " << iter->second << std::endl;  //��ӡmap
//	std::cout << "Can we find lisi?: ";
//	iter = mtmap.find(std::string("lisi"));                        //����
//	if (iter == mtmap.end())                                     //�ж��Ƿ����
//		std::cout << "NO!" << std::endl;
//	else
//		std::cout << "YES!" << std::endl;
//	std::cout << "His id is " << iter->second << std::endl;            //������ڴ�ӡ��ֵ
//	std::cout << std::endl;
//
//	std::cout << "After erase lisi" << std::endl;
//	mtmap.erase(iter);                                            //ɾ��
//	iter = mtmap.begin();
//	for (; iter != mtmap.end(); ++iter)
//		std::cout << "name: " << iter->first << ' ' << "id: " << iter->second << std::endl;
//	system("pause");
//	return 0;
//}