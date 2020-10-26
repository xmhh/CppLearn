#include "stdafx.h"

#include <cstring>
#include <vector>
#include <array>
#include <string>
#include <ctime>

char *getname(void) {
	char temp[100];
	cout << "Please input a string:\n";
	cin >> temp;
	char *pn = new char[strlen(temp) + 1];
	strcpy(pn, temp);
	return pn;
}

void chapter4(void) {
	enum gender { boy, girl };
	char *getname(void);

	struct student {
		string name;
		gender gend;
		long stuID;
		float score;
	};

	cout << "This is the code of chapter 4!" << endl;
	cout << "Remeber to uncomment the codepart you need!" << endl;
	/*4.16
	cout<<"************************************"<<endl;
	string name = "liang";
	string * p_name = &name;

	cout<<"name="<<name<<endl;
	cout<<"p_name="<<p_name<<endl;
	cout<<"&name="<<&name<<endl;
	cout<<"*p_name="<<*p_name<<endl;
	*/
	/*4.17++
	cout<<"************************************"<<endl;
	int *ps = new int;
	int *pp = ps;
	cout<<"*ps Value:\t"<<*ps<<endl;
	cout<<"ps Value:\t"<<ps<<endl;
	cout<<"pp Value:\t"<<pp<<endl;
	delete pp;
	*/
	/*4.18
	cout<<"************************************"<<endl;
	double *parray = new double [5];
	double array [5] = {1,2,3,4,5};
	for(int i=0;i<5;i++){
	parray[i] = 10-array[i];
	cout<<"*(parray+i)="<<*(parray+i)<<endl;
	cout<<"parray[i]="<<parray[i]<<endl;
	cout<<"array[i]="<<array[i]<<endl;
	cout<<"*(array+i)="<<*(array+i)<<endl;
	}
	*/
	/*4.20
	cout<<"************************************"<<endl;
	char animal[20] = "dog";
	const char *bird = "wren";
	char *ps2;

	cout<<"animal="<<animal<<endl;
	cout<<"bird = "<<bird<<endl;
	cout<<"bird(int) = "<<(int*)bird<<endl;
	cout<<"wren(int) = "<<(int*)"wren"<<endl;

	cout<<"please input an animal:"<<endl;
	cin>>animal;
	ps2 = animal;
	cout<<"animal at "<<(int*)animal<<" is "<<animal<<endl;
	cout<<"ps2 at "<<(int*)ps2<<" is "<<ps2<<endl;
	cout<<"*ps2="<<*ps2<<endl;

	ps2 = new char[strlen(animal)+1];
	cout<<"strlen(animal) = "<<strlen(animal)<<endl;
	cout<<"strlen(ps2) = "<<strlen(ps2)<<endl;
	strcpy(ps2,animal);
	cout<<"After string copy:\n";
	cout<<"ps2 at "<<(int*)ps2<<" is "<<ps2<<endl;
	delete [] ps2;
	*/
	/*4.21
	cout<<"************************************"<<endl;
	student class9068[3]={
	{"Bob",boy,31245,80.4},
	{"Mary",girl,31240,86.7},
	{"Kang",boy,31257,70.5}
	};
	student * pc = class9068 + 1;
	cout<<"pc->score is "<<(pc->score)<<endl;
	cout<<"class9068->gend is "<<class9068->gend<<endl;
	cout<<"class9068[2].name is "<<class9068[2].name<<endl;	//class9068[2]->name is not allowed
	cout<<"(*pc).stuID is "<<(*pc).stuID<<endl;	//pc.stuID is not allowed
	*/
	/*4.22
	cout<<"************************************"<<endl;
	char *name;
	name = getname();
	cout<<"name at "<<(int*)name<<" is "<<name<<endl;
	delete [] name;
	name = getname();
	cout<<"name at "<<(int*)name<<" is "<<name<<endl;
	delete [] name;
	*/
	/*4.23
	cout<<"************************************"<<endl;
	struct ayes{int year;};
	ayes y1,y2,y3;
	y1.year = 1998;
	ayes* pa = &y3;
	pa->year = 1840;
	(*(pa-1)).year = 2020;
	cout<<"y1.year = "<<y1.year<<endl;
	cout<<"y2.year = "<<y2.year<<endl;
	cout<<"y3.year = "<<y3.year<<endl;
	ayes ya[4];
	ya[2].year = 2007;
	cout<<(ya+2)->year<<endl;

	ayes* arp[3] = {&y1,&y2,&y3};
	cout<<arp[0]->year<<endl;
	cout<<(**(arp+2)).year<<endl;
	ayes** ppa = arp;
	auto ppb = arp;
	cout<<(*ppa)->year<<endl;
	cout<<(**ppb).year<<endl;
	*/
	/*
	//4.12.13
	int n_int;
	cout<<"Please input an int number:"<<endl;
	cin>>n_int;

	int* mint = new int[n_int];
	cout<<"An int array has been created at "<<mint<<endl;
	cout<<"the length of the array is "<<_msize(mint)/sizeof(*mint)<<endl;
	delete [] mint;

	vector<int> vint[n_int];
	cout<<"You created a vector of size "<<sizeof(vint)/sizeof(vint[0])<<" at "<<vint<<endl;
	*/
	/*
	//4.12.15
	struct fish{
	string type;
	int weight;
	float length;
	};
	fish *pcao = new fish;
	pcao->type = "caoyu";
	pcao->weight = 4;
	(*pcao).length = 7.5;
	cout<<"You get a fish named "<<pcao->type<<endl;
	cout<<"You get a fish weigh "<<pcao->weight<<endl;
	cout<<"You get a fish whose length is  "<<pcao->length<<endl;
	delete pcao;
	*/
	/*
	//4.12.17
	const int n_str = 10;
	std::vector<string> vstr[n_str];
	std::cout<<"vector vstr[10] is created at "<<vstr<<endl;
	std::array<string,n_str> astr;
	//cout<<astr<<endl;         //not allowed
	cout<<&astr<<endl;
	array<string,n_str> *pastr = &astr;
	cout<<"array astr[10] is created at "<<pastr<<endl;
	*/
	/*
	//4.13.1
	struct stu1{
	char firstname[80];
	char lastname[30];
	char grade;
	int age;
	};
	stu1 Yewe;
	cout<<"What is your first name? ";
	cin.getline(Yewe.firstname, 80);
	cout<<"What is your last name? ";
	cin.getline(Yewe.lastname);
	cout<<"What letter grade do you deserve? ";
	cin>>Yewe.grade;
	cout<<"What is your age? ";
	cin>>Yewe.age;
	std::cout<<"Name: "<<Yewe.lastname<<", "<<Yewe.firstname<<endl;
	cout<<"Grade: "<<(char)(Yewe.grade+1)<<endl;
	cout<<"Age: "<<Yewe.age<<endl;
	*/
	/*
	//4.13.2
	struct stu1{
	string firstname;
	string lastname;
	char grade;
	int age;
	};
	stu1 Yewe;
	cout<<"What is your first name? ";
	getline(cin,Yewe.firstname);
	cout<<"What is your last name? ";
	getline(cin,Yewe.lastname);
	cout<<"What letter grade do you deserve? ";
	cin>>Yewe.grade;
	cout<<"What is your age? ";
	cin>>Yewe.age;
	std::cout<<"Name: "<<Yewe.lastname<<", "<<Yewe.firstname<<endl;
	cout<<"Grade: "<<(char)(Yewe.grade+1)<<endl;
	cout<<"Age: "<<Yewe.age<<endl;
	*/
	/*
	//4.13.3
	struct people_name{
	char firstname[60];
	char lastname[30];
	};
	people_name Flem;
	cout<<"Enter your first name: ";
	gets(Flem.firstname);
	cout<<"Enter your last name: ";
	gets(Flem.lastname);
	cout<<"Here's the information in a single string: ";
	cout<<Flem.lastname<<","<<Flem.firstname<<endl;
	*/
	/*
	//4.13.4
	struct people_name{string firstname;string lastname;};
	people_name Flem;
	cout<<"Enter your first name: ";
	getline(cin,Flem.firstname);
	cout<<"Enter your last name: ";
	getline(cin,Flem.lastname);
	cout<<"Here's the information in a single string: ";
	cout<<Flem.lastname<<","<<Flem.firstname<<endl;
	*/
	/*
	//4.13.5
	struct CandyBar{string brand; float weight; int calorie;};
	CandyBar snack = {"Mocha Munch", 2.3, 350};
	cout<<"brand: "+snack.brand<<endl;
	cout<<"weight: "<<snack.weight<<endl;
	cout<<"calorie: "<<snack.calorie<<endl;
	*/
	/*
	//4.13.6
	struct CandyBar{string brand; float weight; int calorie;};
	CandyBar snacks[3] = {
	{"Mocha Munch", 2.3, 350},
	{"Soap",1.8,500},
	{"Sweety",0.44,240}
	};
	for(int i=0; i<3; i++){
	cout<<"snacks["<<i<<"]---"<<"brand: "<<snacks[i].brand<<endl;
	cout<<"snacks["<<i<<"]---"<<"weight: "<<(snacks+i)->weight<<endl;
	cout<<"snacks["<<i<<"]---"<<"calorie: "<<(*(snacks+i)).calorie<<endl;
	};
	*/
	/*
	//4.13.7
	struct pizza{char comp[50];float diameter; float weight;};
	pizza bish;
	cout<<"Please input the company: ";
	cin.getline(bish.comp,50);
	cout<<"Please input the diameer: ";
	cin>>bish.diameter;
	cout<<"Please input the weight: ";
	cin>>bish.weight;
	cout<<"company: "<<bish.comp<<endl;
	cout<<"diameter: "<<bish.diameter<<endl;
	cout<<"weight: "<<bish.weight<<endl;
	*/
	/*
	//4.13.8
	struct pizza{char comp[50];float diameter; float weight;};
	pizza* bish = new pizza;
	cout<<"Please input the diameter: ";
	cin>>bish->diameter;
	cin.get();							//there is a ¡¾CR LF¡¿symbol in the input sequence
	cout<<"Please input the company: ";
	cin.getline(bish->comp,50);
	cout<<"Please input the weight: ";
	cin>>(*bish).weight;
	cout<<"company: "<<bish->comp<<endl;
	cout<<"diameter: "<<bish->diameter<<endl;
	cout<<"weight: "<<bish->weight<<endl;
	delete bish;
	*/
	/*
	//4.13.9
	struct CandyBar{string brand; float weight; int calorie;};
	CandyBar* snacks = new CandyBar[3];
	*snacks = {"Mocha Munch", 2.3, 350},
	(&snacks[0]+1)[0] = {"Soap",1.8,500},
	snacks[2] = {"Sweety",0.44,240};
	for(int i=0; i<3; i++){
	cout<<"snacks["<<i<<"]---"<<"brand: "<<snacks[i].brand<<endl;
	cout<<"snacks["<<i<<"]---"<<"weight: "<<(snacks+i)->weight<<endl;
	cout<<"snacks["<<i<<"]---"<<"calorie: "<<(*(snacks+i)).calorie<<endl;
	};
	delete [] snacks;
	*/
	/*
	//4.13.10
	array<float,3> runscore;
	float avgs = 0;
	for(int i=0; i<3;i++){
	cout<<"Please input the run score "<<i<<":\t";
	cin>>runscore[i];
	avgs = avgs + runscore[i];
	}
	cout<<"The average run score is "<<avgs/3<<endl;
	*/

}