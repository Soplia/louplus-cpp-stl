//#include <iostream>
//#include "xset.h"
//
//int main() {
//	int i;
//	int arr[6] = { 4,2,7,1,9,8 };                    //����һ������
//	std::cout << "Before putting in set: ";
//	for (int i = 0; i < 6; i++)
//		std::cout << arr[i] << " ";                    //�����鸳ֵ
//	std::cout << std::endl;
//
//	jrxstl::set<int> iset(arr, arr + 6);            //����һ��set����
//	std::cout << "lower_bound 2: " << *iset.lower_bound(2) << std::endl;//�ҵ���һ��С�ڵ���2����
//	std::cout << "upper_bound 2: " << *iset.upper_bound(2) << std::endl;//�ҵ���һ������2����
//
//	std::cout << "After insert and put 3: ";
//	iset.insert(3);                                //����
//	jrxstl::set<int>::iterator it;
//	for (it = iset.begin(); it != iset.end(); it++)    //��ӡset
//	{
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;
//	it = iset.find(8);                            //����
//	std::cout << "Can we find 8?: ";
//	if (it == iset.end())                         //�ж��Ƿ����
//		std::cout << "NO!" << std::endl;
//	else
//		std::cout << "YES!" << std::endl;
//	std::cout << std::endl;
//	system("pause");
//	return 0;
//}