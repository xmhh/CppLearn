/*第八章 函数探幽 程序学习*/
#include "stdafx.h"

template<typename T>
inline T square(const T x) { return x*x; };

void swapr(int &a, int & b);
void swapp(int *p, int * q);
void swapv(int a, int b);
double refcube(const double&);
char* left(const char* , int);
unsigned long left(unsigned long, unsigned);

void chapter8()
{
	//using namespace std;
	////内联函数 8.1
	//double a, b;
	//double c = 12.3;
	//a = square<double>(5.0);
	//b = square<double>(4.5+7.5);
	//std::cout << "a = " << a << ",b=" << b << "\n";
	//std::cout << "c=" << c << "c squared =" << square(c++) << std::endl;
	//std::cout << "Now c = " << c << std::endl;
	////引用变量 
	//int rats = 100;
	//int & rodents = rats;	//引用变量必须在声明时就初始化,且不可修改
	////引用变量同常量指针等效	(rodents = *pr1)
	//int const * pr1 = &rats;	//常量指针
	//int  * const pr2 = &rats;	//指针常量
	//const int * pr3 = &rats;	//常量指针,同pr1
	//pr1 = &rats;
	////pr2 = &rats;		//指针常量,不能被修改
	//pr3 = &rats;
	//cout << "rats = " << rats << " at " << &rats << endl;
	//cout << "rodents = " << rodents << " at " << &rodents << endl;
	//cout << "pr1 = " << pr1 << " *pr1 = " << *pr1 << endl;
	//cout << "pr2 = " << pr2 << " *pr2 = " << *pr2 << endl;
	//cout << "pr3 = " << pr3 << " *pr3 = " << *pr3 << endl;

	//int a2 = 100;
	//int b2 = 200;
	//cout << "a2 = " << a2 << ", b2 = " << b2 << endl;
	//swapr(a2, b2);
	//cout << "After swapr, a2 = " << a2 << ", b2 = " << b2 << endl;
	//swapp(&a2, &b2);
	//cout << "After swapp, a2 = " << a2 << ", b2 = " << b2 << endl;
	//swapv(a2, b2);
	//cout << "After swapv, a2 = " << a2 << ", b2 = " << b2 << endl;
	////临时变量
	//double side = 3.0;
	//double* pd = &side;
	//double& rd = side;
	//long edge = 5L;
	//double lens[4] = { 2.0,5.0,10.0,12.0 };
	//double c1 = refcube(side);
	//double c2 = refcube(*pd);		//解除指针引用
	//double c3 = refcube(lens[2]);	//数组元素
	//double c4 = refcube(rd);		//引用变量
	//double c5 = refcube(edge);		//临时变量
	//double c6 = refcube(7.0);		//临时变量
	//double c7 = refcube(side + 10.0);//临时变量
	////右值引用
	//double && rref = sqrt(36.00);
	//double j = 15.0;
	//double&& jref = 2.0 * j + 18.5;
	//cout << "rref = " << rref << "\n";
	//cout << "jref = " << jref << "\n";

	//函数重载
	char* trip = "Hawaii!!";
	unsigned long n = 12345678;
	int i;
	char* temp;
	for (i = 1; i < 10; i++) {
		cout << left(n, i) << endl;
		temp = left(trip, i);
		cout << temp << endl;
		delete[] temp;
	}

};

void swapr(int &a, int & b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
};
void swapp(int *p, int * q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
};
void swapv(int a, int b) {	//无法交换调用函数的a,b的值
	int temp;
	temp = a;
	a = b;
	b = temp;
};
double refcube(const double& ra) {	//尽可能使用const
	return ra * ra * ra;
}

char* left(const char* trip, int n) {
	if (n < 0)	
		n = 0;
	cout << n;
	char *p = new char [n+1];
	int i;
	for (i = 0; i < n; i++) {
		p[i] = trip[i];
	}
	while (i <= n)
		p[i++] = '\0';
	return p;
};

unsigned long left(unsigned long num, unsigned ct) {
	unsigned digits = 1;
	unsigned long n = num;
	if (ct == 0 || num == 0)
		return 0;
	while (n /= 10)
		digits++;
	if (digits > ct) {
		ct = digits - ct;
		while (ct--)
			num /= 10;
		return num;
	}
	else
		return num;
};