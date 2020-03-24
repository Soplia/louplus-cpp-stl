#include <iostream>
#include "xmultiset.h"

int main() {
	jrxstl::multiset<int> imultiset;                        //����һ��multiset
	imultiset.insert(1);                                //����5��ֵ
	imultiset.insert(2);
	imultiset.insert(1);
	imultiset.insert(4);
	imultiset.insert(4);
	std::cout << "After insert ";

	auto it = imultiset.begin();
	for (; it != imultiset.end(); it++)                    //���
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "size:" << imultiset.size() << std::endl;    //����Ԫ�ظ���
	std::cout << "lower_bound 2: " << *imultiset.lower_bound(2) << std::endl;                                            //�ҵ���һ��С�ڵ���2����
	std::cout << "upper_bound 2: " << *imultiset.upper_bound(2) << std::endl;                                            //�ҵ���һ������2����
	it = imultiset.find(2);                                //����
	std::cout << "Can we find 2?: ";
	if (it == imultiset.end())
		std::cout << "NO!" << std::endl;
	else
		std::cout << "YES!" << std::endl;

	std::cout << "After eraase 2" << std::endl;
	imultiset.erase(2);                                    //ɾ��
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