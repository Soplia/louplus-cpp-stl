#include <iostream>
using namespace std;

class Myclass {
public:
	typedef int test;  //�������ͱ���
};

template <class T>
class Myclass2 {
public:
	//T::test *a  // ����
	//typename T::test * a;// ��ȷ
	Myclass::test * a;// ��ȷ
};

//int main()
//{
//	Myclass2<Myclass> a ;
//	system("pause");
//	return 0;
//}