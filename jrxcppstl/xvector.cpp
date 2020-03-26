
#include <iostream>
#include "xvector.h"

int summing(jrxstl::vector<int> val)
{
	int sum = 0;
	jrxstl::vector<int>::iterator ix = val.begin();
	for (; ix != val.end(); ix++)
		sum += *ix;//���
	return sum;
}

void print(jrxstl::vector<int> val) {
	jrxstl::vector<int>::iterator ix = val.begin();
	for (; ix != val.end(); ix++)
		std::cout << *ix << " ";
	std::cout << std::endl;
}

int main()
{
	int sum;
	int input[5];
	std::cout << "enter 5 numbers" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cin >> input[i];//����5������
	}

	jrxstl::vector<int> val(input, input + 5);

	if (val.size() == 0)//�ж�a�Ƿ�Ϊ��
	{
		std::cout << "no element?" << std::endl;
		return -1;
	}

	std::cout << "The vector of val:" << std::endl;
	print(val);

	std::cout << "After insert:" << std::endl;
	jrxstl::vector<int>::iterator it = val.begin();
	jrxstl::advance(it, 2);
	val.insert(it, 2, 3);
	print(val);

	std::cout << "The size of val:" << std::endl;
	std::cout << val.size() << std::endl;

	std::cout << "After pushback:" << std::endl;
	val.push_back(11);
	print(val);

	std::cout << "After erase:" << std::endl;
	val.erase(it);
	print(val);

	std::cout << "After popback:" << std::endl;
	val.pop_back();
	print(val);

	sum = summing(val);
	std::cout << "The sum of val = " << sum << std::endl;

	std::cout << "After sort:" << std::endl;
	jrxstl::vector<int>::iterator beg = val.begin();
	jrxstl::vector<int>::iterator end = val.end();
	jrxstl::sort(beg, end);
	print(val);

	system("pause");
	return 0;
}
