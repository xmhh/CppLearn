#include "stdafx.h"

typedef float * pFL;

void chapter5(void) {
	cout << "This is the code of chapter 5!" << endl;
	cout << "Remeber to uncomment the codepart you need!\n\n" << endl;
	/*
	//5.14
	cout<<"Please enter a delay time in seconds: ";
	float secs;
	cin>>secs;
	clock_t delay = secs*CLOCKS_PER_SEC;
	clock_t start = clock();
	cout<<"CLOCKS_PER_SEC = "<<CLOCKS_PER_SEC<<endl;
	cout<<"Starting at "<<start<<"\a\n";
	while(clock()-start<delay) ;
	cout<<"delay done!\n";
	*/
	float numfl1 = 5.4;
	pFL pnumfl1 = &numfl1;
	cout << pnumfl1 << endl;
}