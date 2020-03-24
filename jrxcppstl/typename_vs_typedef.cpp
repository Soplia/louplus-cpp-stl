#include <iostream>
using namespace std;

class Myclass {
public:
	typedef int test;  //定义类型别名
};

template <class T>
class Myclass2 {
public:
	//T::test *a  // 错误
	//typename T::test * a;// 正确
	Myclass::test * a;// 正确
};

//int main()
//{
//	Myclass2<Myclass> a ;
//	system("pause");
//	return 0;
//}