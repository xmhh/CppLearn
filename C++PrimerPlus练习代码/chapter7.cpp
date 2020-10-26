#include "stdafx.h"
#include <cmath>
struct rect { double x; double y; };
struct polar { double distance; double angle; };
const int ArrSize = 8;

template <typename T> 
T sum_arr(T* arr, int n) {
	T total = 0;
	std::cout << arr << "=arr,";
	std::cout << sizeof arr << "=sizeof arr\n";
	for (int i = 0; i < n; i++) {
		total += arr[i];
	}
	return total;
}
template <typename T>
T sum_arr(const T* begin, const T* end) {
	const T* pt;
	T total = 0;
	for (pt = begin; pt != end; pt++) 
		total += *pt;
	return total;
}
template<typename T>
T sum2_arr(const T * ar2,int size1, int size2) {
	T total = 0;
	for(int i=0;i<size1;i++)
		for (int j = 0; j < size2; j++) {
			total += *(ar2+size1*i+j);
		}
	return total;
}
template<typename T>
void show2_arr(const T* ar2,int size1,int size2) {
	cout << "+++++++++++++++++++++++++++++++++\n";
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			cout << "|"<<(*(ar2 + size2*i + j)) << "\t";
		}
		cout << "|"<<endl;
		if (i!=size1-1)
			cout << "--------------------------------\n";
	}
	cout << "+++++++++++++++++++++++++++++++++\n";
}
int fill_array(double[], int);
void show_array(const double [], int);
void revalue(double, double [], int);
void rect2polar(const rect*, polar*);
rect polar2rect(const polar);
void show_polar(const polar pda);
void show_rect(const rect* pxy);
void subdivide(char ar[], int low, int high, int level);
double betsy(int);
double pam(int);
void estimate(int lines,double (*f)(int));

const double *f1(const double ar[], int n);
const double *f2(const double[], int);
const double *f3(const double *, int);


// the main function of this chapter
void chapter7() {

	/*float cookies[ArrSize] = { 1,2.1,47.1,-2.1,5,0.24,3.2,0 };
	std::cout << cookies << "= array address,";
	std::cout << sizeof cookies << "=sizeof arr";
	float sum = sum_arr(cookies, ArrSize);
	std::cout << "Total cookies eaten: " << sum << std::endl;
	sum = sum_arr(cookies, 3);
	std::cout << "First three eaters ate " << sum << std::endl;
	sum = sum_arr(cookies+4, 4);
	std::cout << "Last four eaters ate " << sum << std::endl;*/

	//double arr1[] = { 4.1, 5.2, 0.11, 2.1, 6.2, 412,2.1,6.4,9.2 };
	//int num = fill_array(arr1, ArrSize);
	//cout << "The number you have input is " << num << endl;
	//int arr_length = sizeof(arr1)/sizeof(arr1[1]);
	//cout << arr_length<<endl;
	//show_array(arr1, arr_length);
	//revalue(0.8, arr1, arr_length);
	//show_array(arr1, arr_length);
	//double sum = sum_arr(arr1, *(&arr1 + 1));
	//cout << "The summary of the array is " << sum << endl;

	////2 dimension array
	//float arr2[][4] = { {1.5,2,2.5,3},{2.1,20.1,0.4,2.1},{1.0} };
	//float sum2 = sum2_arr((float*)arr2, (int)(sizeof(arr2) / sizeof(arr2[0])), 4);
	//cout << "the summary of the 2-D array is " << sum2 << endl;
	//show2_arr((float*)arr2,(int)(sizeof(arr2) / sizeof(arr2[0])),4);

	////input a struct or struct pointer in a function 
	/*rect pxy = { 2.1,5.6 },pxyh;
	polar pda = { 5,45 },*pdah = &pda;
	show_polar(pda);
	show_rect(&pxy);
	pxyh = polar2rect(pda);
	show_rect(&pxyh);
	rect2polar(&pxy, pdah);
	show_polar(*pdah);*/
	////output a ruler-----函数嵌套
	/*const int Len = 66;
	const int Divs = 6;
	char ruler[Len];
	int i;
	for (i = 1; i < Len - 2; i++) 
		ruler[i] = ' ';
	ruler[Len - 1] = '\0';
	int max = Len - 2;
	int min = 0;
	ruler[max] = ruler[min] = '|';
	std::cout << ruler << std::endl;
	for (i = 1; i <= Divs; i++) {
		subdivide(ruler, min, max, i);
		std::cout << ruler << std::endl;
	}*/
	//--//funtion pointer 7.18 fun_ptr.cpp
	/*int code;
	cout << "How many lines of code do you need? ";
	cin >> code;
	cout << "Here is Betsy's estimate:\n";
	estimate(code, betsy);
	cout << "Here is Pam's estimate:\n";
	estimate(code, pam);*/

	//*function pointer array 7.19 arfupt.cpp
	double av[3] = { 1112.3,1542.6,2227.9 };
	//pointer to a function
	const double*(*p1)(const double*, int) = f1;
	auto p2 = f2;
	//const double*(*p2)(const double*, int) = f2;
	cout << "Using pointers to functions:\n";
	cout << "Address Value\n";
	cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
	cout << p2(av, 3) << ": " << *p2(av, 3) << endl;
	//pa 是一个指针数组
	//auto 不能够用来对列表初始化
	const double *(*pa[3])(const double*, int) = { f1,f2,f3 };
	//但是auto可以对列表中的某一个元素初始化
	//pb 是一个指向pa数组第一个元素的指针
	auto pb = pa;
	//pre-C++11 可以使用下面的等效代码
	//const double*(**pb)(const double*,int)=pa;
	cout << "\nUsing an array of pointers to functions:\n";
	cout << " Address  Value\n";
	for (int i = 0; i < 3; i++)
		cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
	cout << "\nUsing a pointer to a pointer to a function:\n";
	cout << " Address  Value\n";
	for (int i = 0; i < 3; i++)
		cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;

	// what about a pointer to an array of function pointers
	cout << "\nUsing pointers to an array of pointers:\n";
	cout << " Address  Value\n";
	// easy way to declare pc 
	auto pc = &pa;
	// pre-C++0x can use the following code instead
	// const double *(*(*pc)[3])(const double *, int) = &pa;
	cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
	// hard way to declare pd
	const double *(*(*pd)[3])(const double *, int) = &pa;
	// store return value in pdb
	const double * pdb = (*pd)[1](av, 3);
	cout << pdb << ": " << *pdb << endl;
	// alternative notation
	cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;
	// cin.get();
}


int fill_array(double ar[], int limit) {
	double temp;
	int i;
	for (i = 0; i < limit; i++) {
		cout << "Enter value #" << (i + 1) << ":";
		cin >> temp;
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input;input process terminated.\n";
			break;
		}
		else if (temp < 0)
			break;
	};
	return i;
}
void show_array(const double arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Property #" << (i + 1) << ":$";
		cout << arr[i] << endl;
	}
}
void revalue(double r, double arr[], int n) {
	for (int i = 0; i < n; i++)
		arr[i] *= r;
}
void rect2polar(const rect*pxy, polar* pda) {
	pda->distance = sqrt(pxy->x*pxy->x + pxy->y*pxy->y);
	pda->angle = atan2(pxy->y, pxy->x);
}
rect polar2rect(const polar pda) {
	rect pxy;
	pxy.x = pda.distance * cos(pda.angle);
	pxy.y = pda.distance * sin(pda.angle);
	return pxy;
}
void show_polar(const polar pda){
	cout << "The polar coordinate is :\t";
	cout << "distance: " << pda.distance<<"\t";
	cout << "angle: " << pda.angle<<endl;
}
void show_rect(const rect* pxy) {
	cout << "The rectangle coordinate is :\t";
	cout << "rect_x: " << pxy->x<<"\t";
	cout << "rect_y: " << pxy->y << endl;
}
void subdivide(char ar[], int low, int high, int level) {
	if (level == 0)
		return;
	int mid = (high + low) / 2;
	ar[mid] = '|';
	subdivide(ar, low, mid, level - 1);
	subdivide(ar, mid, high, level - 1);
}
double betsy(int ls) {
	return 0.05*ls;
}
double pam(int ls) {
	return 0.03*ls + 0.04*ls*ls;
}
void estimate(int lines, double(*pf)(int)) {
	cout << lines << " Lines will take ";
	cout << (*pf)(lines) << "hour(s)\n";
}

const double *f1(const double *ar, int n) {
	return ar;
}
const double *f2(const double ar[], int n) {
	return ar + 1;
}
const double *f3(const double ar[], int n) {
	return ar + 2;
}
//习题7.12.13
struct applicant {
	char name[30];
	int credit_ratings[3];
};
void(*pf1)(applicant *);
//const char* ((*pf2)[2])(const applicant *a1, const applicant *a2);//不允许使用函数数组
const char* (*(*pf2)[2])(const applicant *a1, const applicant *a2);